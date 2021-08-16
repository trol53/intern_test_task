cmake_minimum_required(VERSION 3.16)
project(server)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_compile_options(
        -Wall
        -Wextra
)

add_executable(server
        check.cpp
        main.cpp
        server.cpp
        sock.cpp
        solve.cpp
        )
find_package(cppzmq)
target_link_libraries(server cppzmq pthread)
set_target_properties(server PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
        )

