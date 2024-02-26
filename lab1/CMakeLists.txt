cmake_minimum_required(VERSION 3.10)
project(lab_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

add_library(car_lib ${SOURCE_DIR}/car_number.cpp)

add_executable(${CMAKE_PROJECT_NAME}.exe main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}.exe PUBLIC car_lib)