#ifndef STANDARD_FEATURES_MEYERS_TEMPLATETYPEDEDUCTION_HPP
#define STANDARD_FEATURES_MEYERS_TEMPLATETYPEDEDUCTION_HPP



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

template<typename T, std::size_t N>
void printCaption(T (&capValue)[N]  ) {
    std::cout << std::endl <<
"************************************************************************************************************************" <<
    capValue << std::endl <<
"************************************************************************************************************************" <<
    std::endl << std::endl;
};

template<typename T, std::size_t N>
constexpr void compileTimePrint(T (&StringParam)[N]) {
  std::cout << StringParam << std::endl;
}

void printArrayTypeDeductionSpecific() {

  printCaption("C-style array type deduction:");
  const char chArr[] = {'a', 'b', 'c', 'd', 'e'};
  refParamDeductInfo(chArr, "const char [5]");
};

void printTypeDeductionTips() {

  printCaption("Template function type deduction:");

  int i = 1;
  int const ci = 2;
  int const & cri = ci;

  paramDeductInfo(i, "int");
  paramDeductInfo(ci, "int const");
  paramDeductInfo(cri, "int const &");

  std::cout << std::endl;


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
  unvRefParamDeductInfo(1, "rvalue, int");
}

template<typename OrigT>
void printPrompt(const char * paramTypeView) {

  std::cout << "variable type: " << type_id_with_cvr<OrigT>().pretty_name() << std::endl;
  std::cout << "parameter type: " << paramTypeView << std::endl;
  std::cout << "enter result type:";

}

template<typename OrigT, typename RuleFuncT>
void singleTest(const char * paramTypeView, RuleFuncT ruleFunc) {

  printPrompt<OrigT>(paramTypeView);
  std::string resultType;
  std::cin >> resultType;

  std::cout << "deduction rule is: ";

  OrigT var;
  std::string originalTypePrettyName = type_id_with_cvr<OrigT>().pretty_name();
  std::string resultTypeEtalon = ruleFunc(var, originalTypePrettyName.c_str());

  std::cout << (resultTypeEtalon == resultType ? "all right" : "incorrect") << std::endl;

}


#endif //STANDARD_FEATURES_MEYERS_TEMPLATETYPEDEDUCTION_HPP
