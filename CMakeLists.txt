cmake_minimum_required(VERSION 3.10.0)
project(ed-1-exercicios VERSION 0.1.0 LANGUAGES C CXX)

include_directories(../ifsul-cpp/lib)

add_executable(L05-03 L05-03/main.cpp)
add_executable(L05-04 L05-04/main.cpp L05-04/lib/menu.cpp)
add_executable(L03-03 L03-03/main.cpp)
add_executable(L03-04 L03-04/main.cpp)
add_executable(L03-05 L03-05/main.cpp)
add_executable(L09-01 L09-01/main.cpp L09-01/lib/menu.cpp)
