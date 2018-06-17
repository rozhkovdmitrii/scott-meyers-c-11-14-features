#include <iostream>
#include <typeinfo>

#include <boost/type_index.hpp>

using namespace boost::typeindex;

template<typename T>
void paramDeductInfo(T param, const char * initType) {
  std::cout << initType  << " -> (T param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};

template<typename T>
void refParamDeductInfo(T& param, const char * initType) {
  std::cout << initType  << " -> (T &param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};


template<typename T>
void constrefParamDeductInfo(const T & param, const char * initType) {
  std::cout << initType  << " -> (const T &param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};

template<typename T>
void ptrParamDeductInfo(T * param, const char * initType) {
  std::cout << initType  << " -> (T *param) -> "
            << type_id_with_cvr<T>().pretty_name()
            << std::endl;
};

template<typename T>
void unvRefParamDeductInfo(T && param, const char * initType) {
  std::cout << initType  << " -> (T &&param) -> "
            << type_id_with_cvr<T>().pretty_name() << ", param - " << type_id_with_cvr<decltype(param)>().pretty_name()
            << std::endl;
};

int main() {
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

  unvRefParamDeductInfo(i, "lvalue int");
  unvRefParamDeductInfo(ci, "lvalue const int");
  unvRefParamDeductInfo(cri, "lavlue const int &");
  unvRefParamDeductInfo(1, "rvalue int");

  return 0;
}