cmake_minimum_required(VERSION 3.20)
project(CTR)

set(CMAKE_CXX_STANDARD 14)

add_executable(CTR main.cpp CTR.cpp CTR.h CTRLane.cpp CTRLane.h CTRPlayer.cpp CTRPlayer.h)
