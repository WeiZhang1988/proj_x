cmake_minimum_required(VERSION 3.5)
project(test_algorithm_x)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


include_directories(${PROJECT_SOURCE_DIR}/../include)

if(NOT GTEST_DIR)
  set(GTEST_DIR ${CMAKE_SOURCE_DIR}/../../../third_party/googletest)
endif()
if( IS_DIRECTORY ${GTEST_DIR} )
  add_subdirectory( ${GTEST_DIR} gtest.out)
else()
  message(FATAL_ERROR   "INVALID FOLDER 'GTEST_DIR'=${GTEST_DIR}" )
endif()

include(CTest)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
add_executable(test_algorithm_x test_algorithm_x.cpp ${PROJECT_SOURCE_DIR}/../src/algorithm_x.cpp)
target_link_libraries(test_algorithm_x gtest gtest_main pthread)
add_test(NAME test_algorithm_x COMMAND test_algorithm_x)
