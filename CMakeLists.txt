cmake_minimum_required(VERSION 3.10)
project(standard_features_meyers)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp-template-type-deduction 1.1-type-deduction/main.cpp 1.1-type-deduction/templateTypeDeduction.cpp 1.1-type-deduction/templateTypeDeduction.hpp)