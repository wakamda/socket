project(udpsocket)
cmake_minimum_required(VERSION 2.8.0)


#compile flags
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -Wall -O0 -g -ggdb -fPIC -std=gnu99 ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -g -ggdb -fPIC -std=c++0x")


#build .so
include_directories(${PROJECT_SOURCE_DIR}/api)
include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(./src SRC_DIR)

add_library(sd_sdk SHARED ${SRC_DIR})
#target_link_libraries(sd_sdk )

#build exe
 
set(LIB_OUT_DOR ${PROJECT_SOURCE_DIR}/build)
link_directories(${LIB_OUT_DOR})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/api)

add_executable(test test/test.cpp)
target_link_libraries(test sd_sdk)

add_executable(send test/send.cpp)
add_executable(receive test/recrive.cpp)