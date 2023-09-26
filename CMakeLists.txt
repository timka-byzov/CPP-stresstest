cmake_minimum_required(VERSION 3.26)
project(CPP_stresstest)

set(CMAKE_CXX_STANDARD 17)

include_directories(module1/stress-A)
include_directories(module1/stress-B)

add_executable(CPP_stresstest
        module1/stress-A/comparer.cpp
        #module1/stress-B/comparer.cpp
)
