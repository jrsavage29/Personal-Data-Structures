cmake_minimum_required(VERSION 3.5)
project(region_grower CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build the image library
ADD_SUBDIRECTORY(lib)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib)

ADD_EXECUTABLE(color2grayscale color2grayscale.cpp)
TARGET_LINK_LIBRARIES(color2grayscale image)

set(NODE_SOURCE
  Node.hpp )

set(STACK_SOURCE
  Stack.hpp )

set(REGION_SOURCE
  region_grower.hpp region_grower.cpp )
  
ADD_EXECUTABLE(fillregion fillregion.cpp ${NODE_SOURCE} ${STACK_SOURCE} ${REGION_SOURCE})
TARGET_LINK_LIBRARIES(fillregion image)

enable_testing()
add_test(color2grayscale color2grayscale
${CMAKE_SOURCE_DIR}/beamer_celebration.png beamer_celebration-gray.png)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  Stack.txx ${REGION_SOURCE} fillregion.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
