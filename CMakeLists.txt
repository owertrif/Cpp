cmake_minimum_required(VERSION 3.24)
project(Part2)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

include_directories(Part2)

add_executable(Part2
        Part2/Game.cpp
        Part2/Game.h
        Part2/main.cpp
        Part2/Player.cpp
        Part2/Player.h
        Part2/SwagBall.cpp
        Part2/SwagBall.h
        )

target_link_libraries(Part2 sfml-graphics sfml-audio)
