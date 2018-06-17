cmake_minimum_required(VERSION 3.10)
project(standard_features_meyers)

set(CMAKE_CXX_STANDARD 11)

include_directories($ENV{BOOST_INCLUDE})

add_executable(1.1-type-deduction 1-type-deduction/main.cpp cli-lib/cli.h cli-lib/cli-lib.cpp)