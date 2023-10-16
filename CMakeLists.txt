cmake_minimum_required(VERSION 3.20)
project(CPP_stresstest)

set(CMAKE_CXX_STANDARD 17)

include_directories(module2/stress-A)
include_directories(module1/stress-B)

add_executable(CPP_stresstest
        module2/stress-E/solution3.cpp
)
