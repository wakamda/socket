
project(TCP_socket)
cmake_minimum_required(VERSION 3.16)

add_executable(svr_base TCP/server_base.cpp)
add_executable(cit_base TCP/client_base.cpp)