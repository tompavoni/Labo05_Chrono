cmake_minimum_required(VERSION 3.20)
project(Labo05_Chrono)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Werror -Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(Labo05_Chrono main.cpp fonction.h fonction.cpp)
