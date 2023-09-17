cmake_minimum_required(VERSION 3.26)
project(PA1)

set(CMAKE_CXX_STANDARD 17)

add_executable(PA1 main.cpp
        LinkedList.h
        Node.h
        Game.cpp
        Game.h
        profile.cpp
        profile.h)
