cmake_minimum_required(VERSION 3.5)
project(HW6 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NODE_SOURCE
  Node.hpp )

set(INGREDIENT_SOURCE
  Ingredient.cpp Ingredient.h )
  
set(RECIPE_SOURCE
  Recipe.cpp Recipe.h )
  
set(BST_SOURCE
  BST.hpp )

set(TEST_SOURCE
  student_tests.cpp)

set(SOURCE ${BST_SOURCE} ${TEST_SOURCE} ${NODE_SOURCE})

# create unittests
add_executable(student-tests catch.hpp ${BST_SOURCE} ${NODE_SOURCE} ${TEST_SOURCE} ${INGREDIENT_SOURCE} ${RECIPE_SOURCE})

# some simple tests
enable_testing()
add_test(student-tests student-tests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  Node.cpp ${BST_SOURCE} student_tests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})