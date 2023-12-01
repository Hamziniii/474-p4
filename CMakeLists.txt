cmake_minimum_required(VERSION 3.26)
project(474_p4)

set(CMAKE_CXX_STANDARD 11)

add_executable(474_p4 main.cpp
        Invoker.cpp
        Invoker.h
        Receiver.cpp
        Receiver.h
        LinkedList.cpp
        LinkedList.h
        Instruction.cpp
        Instruction.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/input.wl
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})