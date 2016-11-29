cmake_minimum_required(VERSION 3.6)
project(swervelib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        swervelib.cpp
        swervelib.hpp)

add_library(swervelib SHARED ${SOURCE_FILES})
