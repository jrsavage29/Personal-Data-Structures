cmake_minimum_required(VERSION 3.2)
project(Stack CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(student_tests Stack.hpp Node.hpp catch.hpp student_tests.cpp)

enable_testing()

add_test(student_tests student_tests)
