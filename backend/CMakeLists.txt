cmake_minimum_required(VERSION 3.16)
project(monopoly_arcade_server LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SERVER_SOURCES CONFIGURE_DEPENDS
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(monopoly_server ${SERVER_SOURCES})
target_include_directories(monopoly_server PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
