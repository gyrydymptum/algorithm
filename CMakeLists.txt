cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 20)
project(WordCountCompetition)
#add_compile_options(${PROJECT_NAME} -Wall -Wextra -Wconversion -pedantic -Werror)

add_executable(wc main.cpp Counter.cpp)
