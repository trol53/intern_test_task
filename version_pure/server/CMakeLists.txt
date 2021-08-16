cmake_minimum_required(VERSION 3.16)
project(server)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)


add_executable(server
        check.cpp
        main.cpp
        sock.cpp
        solve.cpp
        server.cpp)
target_link_libraries(server pthread)
