cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(WordCountCompetition)

add_executable(wc main.cpp Counter.cpp)
add_compile_options(${PROJECT_NAME} -Wall -Wextra -Wconversion -pedantic -Werror -O3)