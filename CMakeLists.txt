cmake_minimum_required(VERSION 3.16)
project(konkurs)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp DicePoker.cpp Dice.cpp NextState.cpp SimpleTest.cpp)
add_executable(${PROJECT_NAME}-ut Catch2Tests.cpp catch_amalgamated.cpp DicePoker.cpp Dice.cpp NextState.cpp)

enable_testing()
add_test(NAME Tests-catch2 COMMAND ${PROJECT_NAME}-ut)