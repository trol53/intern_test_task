cmake_minimum_required(VERSION 3.16)
project(client)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_compile_options(
        -Wall
        -Wextra
)

add_executable(client
        main.cpp
        sock.cpp
        )
find_package(cppzmq)
target_link_libraries(client cppzmq pthread)
set_target_properties(client PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
        )

