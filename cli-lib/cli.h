#ifndef STANDARD_FEATURES_MEYERS_CLI_H
#define STANDARD_FEATURES_MEYERS_CLI_H

#include <iostream>
#include <type_traits>

namespace cli
{
template<typename T, std::size_t N>
constexpr void printCaption(T (&capValue)[N])
{
  static_assert(N <= 120, "caption length should be less than 120");
  std::cout << std::endl <<
            "************************************************************************************************************************"
            << std::endl << capValue << std::endl <<
            "************************************************************************************************************************"
            << std::endl << std::endl;
};
}
#endif //STANDARD_FEATURES_MEYERS_CLI_H
