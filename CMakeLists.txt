cmake_minimum_required(VERSION 3.2)

project(s-terra VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread -Werror")

add_executable (main main.cpp handlers/handlers_iface.h handlers/create_handler.h handlers/create_handler.cpp helpers/tree.h helpers/tree.cpp)
