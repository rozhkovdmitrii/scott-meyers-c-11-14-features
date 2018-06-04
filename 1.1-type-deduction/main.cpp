#include <iostream>
#include <typeinfo>
#include <boost/type_index.hpp>



namespace
{

using namespace boost::typeindex;

template<typename T>
std::string paramDeductInfo(T param, const char *initType)
{
  std::string resultType = type_id_with_cvr<T>().pretty_name();
  std::cout << initType << " -> (T param) -> "
            << resultType << std::endl;
  return resultType;
};

template<typename T>
void refParamDeductInfo(T &param, const char *initType)
{
  std::cout << initType << " -> (T &param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};


template<typename T>
void constrefParamDeductInfo(const T &param, const char *initType)
{
  std::cout << initType << " -> (const T &param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};

template<typename T>
void ptrParamDeductInfo(T *param, const char *initType)
{
  std::cout << initType << " -> (T *param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};

template<typename T>
void unvRefParamDeductInfo(T &&param, const char *initType)
{
  std::cout << initType << " -> (T &&param) -> "
            << type_id_with_cvr<T>().pretty_name() << ", param - " << type_id_with_cvr<decltype(param)>().pretty_name()
            << std::endl;
};

void printHelpMsg() {
  std::cout << "Usage:"
               "cpp-type-deduction [--testme|--tips]" << std::endl;

}

void printTypeDeductionTips() {
  int i = 1;
  int const ci = 2;
  int const & cri = ci;

  refParamDeductInfo(i, "int");
  refParamDeductInfo(ci, "int const");
  refParamDeductInfo(cri, "int const &");

  std::cout << std::endl;

  constrefParamDeductInfo(i, "int");
  constrefParamDeductInfo(ci, "int const");
  constrefParamDeductInfo(cri, "int const &");

  std::cout << std::endl;

  char const * const cp2cch = "Hi everybody!!";
  paramDeductInfo(cp2cch, "char const * const");
  ptrParamDeductInfo(cp2cch, "char const * const");

  std::cout << std::endl;
  unvRefParamDeductInfo(i, "lvalue int");
  unvRefParamDeductInfo(ci, "lvalue const int");
  unvRefParamDeductInfo(cri, "lavlue const int &");
  unvRefParamDeductInfo(reinterpret_cast<int>(1), "rvalue, int");
}
}

template<typename OrigT, typename RuleFuncT>
void singleTest(const char * ParamTypeView, RuleFuncT ruleFunc)
{

  std::cout << "variable type: " << type_id_with_cvr<OrigT>().pretty_name() << std::endl;
  std::cout << "parameter type: " << ParamTypeView << std::endl;
  std::cout << "enter result type:";

  std::string resultType;
  std::cin >> resultType;

  std::cout << "deduction rule is: ";

  OrigT var;
  std::string originalTypePrettyName = type_id_with_cvr<OrigT>().pretty_name();
  std::string resultTypeEtalon = ruleFunc(var, originalTypePrettyName.c_str());

  std::cout << std::endl << "you are " << (resultTypeEtalon == resultType ? "right" : "wrong") << std::endl;

}

int main(int argc, const char **argv) {
  if (argc == 2 && strcmp("--tips", argv[1]) == 0)
    printTypeDeductionTips();
  else if (argc == 2 && strcmp("--testme", argv[1]) == 0)
    singleTest<int>("T", paramDeductInfo);
  else
    printHelpMsg();
  return 0;
}