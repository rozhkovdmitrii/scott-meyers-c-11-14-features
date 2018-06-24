#include <iostream>
#include "templateTypeDeduction.hpp"

int main(int argc, const char **argv) {

  if (argc == 2 && strcmp("--tips", argv[1]) == 0) {
    printTypeDeductionTips();
  } else if (argc == 2 && strcmp("--testme", argv[1]) == 0) {
    std::cout << "this facility is not complete yet" << std::endl;
  } else
    printHelpMsg();
  return 0;
}
