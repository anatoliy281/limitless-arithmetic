cmake_minimum_required(VERSION 3.5)

project(test-catch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(SRC
	../limitlessint.cpp
	limitlessint-test.cpp
)

find_package(Catch2 3 REQUIRED)

add_executable(${PROJECT_NAME} ${SRC} ${PROJ_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2WithMain)
