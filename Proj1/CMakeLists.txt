cmake_minimum_required(VERSION 3.5)
project(P1 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the image library
ADD_SUBDIRECTORY(lib)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

# build the compare program
ADD_EXECUTABLE(compare compare.cpp)
TARGET_LINK_LIBRARIES(compare image)

set(COMPLEX_SOURCE
  complex.hpp complex.cpp)

set(MANDELBROT_SOURCE
  mandelbrot.hpp mandelbrot.cpp)

set(TEST_SOURCE
  student_tests.cpp)

set(FRACTAL_SOURCE fractal.cpp)

set(SOURCE ${COMPLEX_SOURCE} ${MANDELBROT_SOURCE} ${TEST_SOURCE} ${FRACTAL_SOURCE})

# create unittests
add_executable(student-tests catch.hpp ${COMPLEX_SOURCE} ${MANDELBROT_SOURCE} ${TEST_SOURCE})
TARGET_LINK_LIBRARIES(student-tests image)

# build executable
add_executable(fractal ${COMPLEX_SOURCE} ${MANDELBROT_SOURCE} ${FRACTAL_SOURCE})
TARGET_LINK_LIBRARIES(fractal image)

# some simple tests
enable_testing()
add_test(student-tests student-tests)
add_test(test00-compare compare ${CMAKE_SOURCE_DIR}/tests/fractal.png fractal.png)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  ${SOURCE}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
