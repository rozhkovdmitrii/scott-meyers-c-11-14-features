#include <iostream>
#include <boost/type_index.hpp>

#include "templateTypeDeduction.hpp"

int main(int argc, const char **argv) {


  std::string ggbb = "asdfasdfasd";
  ggbb += std::to_string(12);
  std::cout <<ggbb;

  compileTimePrint("Hi everyone");

  if (argc == 2 && strcmp("--tips", argv[1]) == 0) {
    printTypeDeductionTips();
    printArrayTypeDeductionSpecific();
  } else if (argc == 2 && strcmp("--testme", argv[1]) == 0) {
    std::cout << "this facility is not complete yet" << std::endl;
  } else
    printHelpMsg();
  return 0;
}