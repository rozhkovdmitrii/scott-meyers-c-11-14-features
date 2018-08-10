cmake_minimum_required(VERSION 3.10)
project(standard_features_meyers)

set(CMAKE_CXX_STANDARD 17)

include_directories($ENV{BOOST_INCLUDE})

add_executable(cpp-template-type-deduction
	1-type-deduction/main.cpp
	1-type-deduction/templateTypeDeduction.cpp
	1-type-deduction/templateTypeDeduction.hpp
	cli-lib/cli.h
	cli-lib/cli-lib.cpp)

target_include_directories(cpp-template-type-deduction PUBLIC cli-lib)

add_executable(arr-and-func-type-deduction
  2-type-deduction-for-arrays-and-functions/main.cpp
  cli-lib/cli.h
  cli-lib/cli-lib.cpp)

target_include_directories(arr-and-func-type-deduction PUBLIC 1-type-deduction cli-lib)


add_executable(auto-samples 3-auto/main.cpp)
