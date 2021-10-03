cmake_minimum_required(VERSION 3.5)

project(abc_hw) #" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(abc_hw main.cpp)

add_executable(abc_hw main.cpp
    truck.h
    truck.cpp
    transportation.h
    transportation.cpp
    container.h container.cpp
    bus.h bus.cpp
    car.h car.cpp)
