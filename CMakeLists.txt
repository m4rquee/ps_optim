cmake_minimum_required(VERSION 3.19)
project(ps_optim)

set(CMAKE_CXX_STANDARD 20)

include_directories("include/eigen")
include_directories("include/optim")
include_directories("include/ps_optim")

add_executable(ps_optim src/main.cpp)