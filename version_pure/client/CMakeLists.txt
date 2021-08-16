cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(client
        main.cpp
        sock.cpp
        )

