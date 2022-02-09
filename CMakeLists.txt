cmake_minimum_required(VERSION 3.5)

project(bits LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(test-catch)

add_executable(${PROJECT_NAME} main.cpp limitlessint.cpp limitlessint.hpp)
