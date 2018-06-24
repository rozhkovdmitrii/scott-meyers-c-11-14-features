#ifndef STANDARD_FEATURES_MEYERS_TEMPLATETYPEDEDUCTION_HPP
#define STANDARD_FEATURES_MEYERS_TEMPLATETYPEDEDUCTION_HPP

#include <iostream>
#include <boost/type_index.hpp>

using namespace boost::typeindex;

template<typename T>
void paramDeductInfo(T param, const char *initType)
{
  std::cout << initType << " -> (T param) -> "
            << type_id_with_cvr<T>().pretty_name() << std::endl;
};

template <typename T>
void constParamDeductInfo(const T param, const char *initType)
{
  std::cout << initType << " -> (const T param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
}

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

void printHelpMsg();

template<typename T, std::size_t N>
constexpr void compileTimePrint(T (&StringParam)[N]) {
  std::cout << StringParam << std::endl;
}

void printArrayTypeDeductionSpecific();

void printTypeDeductionTips();

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
