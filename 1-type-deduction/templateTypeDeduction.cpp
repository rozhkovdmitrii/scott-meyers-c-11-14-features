#include <iostream>
#include "templateTypeDeduction.hpp"


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

void printHelpMsg() {
    std::cout << "Usage:"
    "cpp-type-deduction [--testme|--tips]" << std::endl;
}

void printArrayTypeDeductionSpecific() {
    printCaption("C-style array type deduction:");
    const char chArr[] = {'a', 'b', 'c', 'd', 'e'};
    refParamDeductInfo(chArr, "const char [5]");
};
