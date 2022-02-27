cmake_minimum_required(VERSION 3.20)
project(Flappy)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flappy main.cpp FlappyBIrds.cpp FlappyBIrds.h Bird.cpp Bird.h FlappyMap.cpp FlappyMap.h)
