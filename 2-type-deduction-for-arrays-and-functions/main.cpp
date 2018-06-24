#include "../1-type-deduction/templateTypeDeduction.hpp"
#include "cli.h"

/*void getAssertInPrintCaption() {
  cli::printCaption("123456789 123456789 123456789 123456789 123456789 123456789 123456789"
                    "123456789 123456789 123456789 123456789 123456789 !");
}*/

int main(int argc, const char **argv) {

  cli::printCaption("TYPE DEDUCTION FOR ARRAY OF CHAR");

  char charSeq[] = "Hi everyone!";
  paramDeductInfo(charSeq, "char []");
  refParamDeductInfo(charSeq, "char []");

  cli::printCaption("TYPE DEDUCTION FOR ARRAY OF INT");
  int intSeq[] = {1, 2, 3};
  paramDeductInfo(intSeq, "int []");
  refParamDeductInfo(intSeq, "int []");

  cli::printCaption("TYPE DEDUCTION FOR ARRAY OF CLASS A");
  class A {
  } const classASeq[] = {A(), A(), A()};

  paramDeductInfo(classASeq, "class A[]");
  refParamDeductInfo(classASeq, "class A[]");

}