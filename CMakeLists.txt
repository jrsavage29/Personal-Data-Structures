cmake_minimum_required(VERSION 3.2)
project(Complex2574 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(complex_main complex.hpp complex.cpp complex_main.cpp)
add_executable(complex_test complex.hpp complex.cpp catch.hpp complex_test.cpp)

enable_testing()

add_test(complex_test complex_test)
