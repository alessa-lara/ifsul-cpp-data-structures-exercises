cmake_minimum_required(VERSION 3.10.0)
project(ed-1-exercicios VERSION 0.1.0 LANGUAGES C CXX)

include_directories(../ifsul-cpp/lib)

add_executable(L05-03 L05-03/main.cpp)
add_executable(L05-04 L05-04/main.cpp L05-04/lib/menu.cpp)