#include <iostream>
#include <boost/type_index.hpp>
#include <functional>
#include <bits/unordered_map.h>
#include <unordered_map>
class A {

public:
  std::string _value;
  A(): _value("A default") {

  }

  A(const std::initializer_list<int> & list): _value("A from initializer list") {


  }

  A(const int p1, const std::string & p2): _value("constructed from 2 parameters")  {

  }

  A(const double p1, const double p2): _value("constructed from 2 double")  {

  }
};

struct B {
  int a;
  int b;
  int c;
};


template<typename T>
void func(const std::initializer_list<T> & param) {

}

template<typename T> struct vec {
  vec(std::initializer_list<T>){};
};


const auto ff(const std::string & str) {
  auto ggbb = [& str](const auto & value)

  {
    return str;
  };
  return ggbb;
}

int main(int argc, const char **argv)  {

  auto a = 1;
  auto b = {1,2};

/*  A c {1., 11.};*/

/*  std::cout << c._value;*/


  vec<int> v1{{{}}};


  B d {.a = 1, 3,  .c = 3};

  auto ar = a;
  decltype(auto) arr = a;


  const int i = 0;

  decltype((i)) j = i;

  std::cout << "int const i = 0;" << std::endl << "decltype(i) is "
            << boost::typeindex::type_id_with_cvr<decltype(i)>().pretty_name() << std::endl;

  std::cout << "decltype((i)) is "
            << boost::typeindex::type_id_with_cvr<decltype((i))>().pretty_name() << std::endl;

  long long l = 100000000000;
  auto shouldBeLong = 0;
  shouldBeLong = l;

  std::cout << boost::typeindex::type_id_with_cvr<decltype(shouldBeLong)>().pretty_name() << std::endl;

  auto lambda = ([](){ return 555; });
  std::function<void()> function = ([]{ return 777;});

  std::cout << "Type of lambda declaread as auto: " << boost::typeindex::type_id_with_cvr<decltype(lambda)>().pretty_name() << std::endl;
  std::cout << "Type of lambda declared as std::function: " << boost::typeindex::type_id_with_cvr<decltype(function)>().pretty_name() << std::endl;

  std::unordered_map<std::string, int> m;

/*  for (const auto & p: m)
    std::cout << p.second << std::endl;*/

}


