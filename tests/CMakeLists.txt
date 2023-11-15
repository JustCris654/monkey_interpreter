cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -O0")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# run google tests
enable_testing()

add_executable(
  lexer_test
  ${CMAKE_SOURCE_DIR}/tests/lexer_test.cpp
  ${CMAKE_SOURCE_DIR}/src/token/token.cpp
  ${CMAKE_SOURCE_DIR}/src/lexer/lexer.cpp)
target_include_directories(lexer_test PRIVATE src/token src/lexer)
target_link_libraries(lexer_test GTest::gtest_main)

add_executable(
  parser_test
  ${CMAKE_SOURCE_DIR}/tests/parser_test.cpp ${CMAKE_SOURCE_DIR}/src/ast/ast.cpp
  ${CMAKE_SOURCE_DIR}/src/token/token.cpp
  ${CMAKE_SOURCE_DIR}/src/lexer/lexer.cpp)
target_include_directories(parser_test PRIVATE src/ast src/token src/lexer)
target_link_libraries(parser_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lexer_test parser_test)
