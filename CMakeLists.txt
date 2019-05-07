cmake_minimum_required(VERSION 3.5.1)
project(rl_cpp_framework VERSION "1.0.0")




if (CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_BUILD_TYPE "Release")
else()
    add_definitions(-DDEBUG)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()
message("-- Current Mode: " ${CMAKE_BUILD_TYPE})


SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -w -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -w")


add_definitions(-std=c++11)
add_definitions(-D__LINUX__=1)
find_package(Boost REQUIRED COMPONENTS system thread)

add_definitions(-DBOOST_UTILS=1)
add_definitions(-DBOOST_MODE=1)

#Global include path for all libs.
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(_public)
add_subdirectory(_async)
# add_subdirectory(_grpc)
# add_subdirectory(_http)
add_subdirectory(_json)
add_subdirectory(_log)
# add_subdirectory(_mmap)
# add_subdirectory(_mysql)
# add_subdirectory(_redis)
# add_subdirectory(_sqlite)
# add_subdirectory(_websocket)
# add_subdirectory(_xml)
# add_subdirectory(_zmq)
add_subdirectory(tests)
add_custom_target(open_coredump ALL COMMAND ulimit -c unlimited)