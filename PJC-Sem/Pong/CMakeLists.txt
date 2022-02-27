cmake_minimum_required(VERSION 3.20)
project(Pong)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pong main.cpp Paddle.cpp Paddle.h Ball.cpp Ball.h Pong.cpp Pong.h)
