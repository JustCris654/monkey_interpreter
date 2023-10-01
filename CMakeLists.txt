cmake_minimum_required(VERSION 3.19)

project(monkey_interpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -O0")

# find packages

# fetch google test
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
include(GoogleTest)
gtest_discover_tests(lexer_test)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp ${CMAKE_SOURCE_DIR}/src/token/token.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/lexer.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE src/token src/lexer)

# target_include_directories
