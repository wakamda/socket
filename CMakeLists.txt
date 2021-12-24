
project(TCP_socket)
cmake_minimum_required(VERSION 3.16)

add_executable(client1 TCP/client.cpp)
add_executable(client2 TCP/client2.cpp)
add_executable(server TCP/server.cpp)