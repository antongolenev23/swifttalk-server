cmake_minimum_required(VERSION 3.15)
project(SwiftTalkServer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_PATH "../sources")

find_package(Boost REQUIRED)

add_executable(swift_talk_server 
    ${SRC_PATH}/main.cpp
    ${SRC_PATH}/server.cpp
    ${SRC_PATH}/client_session.cpp
    ${SRC_PATH}/connection.cpp
)

target_include_directories(swift_talk_server PRIVATE 
    ${Boost_INCLUDE_DIRS}
    include
)