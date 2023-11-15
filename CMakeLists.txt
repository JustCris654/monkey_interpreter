cmake_minimum_required(VERSION 3.19)

project(monkey_interpreter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g -O0")

# find packages

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/src/token/token.cpp
    ${CMAKE_SOURCE_DIR}/src/lexer/lexer.cpp
    ${CMAKE_SOURCE_DIR}/src/repl/repl.cpp
    ${CMAKE_SOURCE_DIR}/src/ast/ast.cpp
    ${CMAKE_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE ${CMAKE_SOURCE_DIR}/src/token ${CMAKE_SOURCE_DIR}/src/lexer
          ${CMAKE_SOURCE_DIR}/src/repl ${CMAKE_SOURCE_DIR}/src/ast)

include(tests/CMakeLists.txt)
