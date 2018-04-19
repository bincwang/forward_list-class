cmake_minimum_required(VERSION 3.2)

project(hw8)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/src)
set (HEADERS
  ${PROJECT_SOURCE_DIR}/src/forward_list.h)

add_executable(hw8 ${PROJECT_SOURCE_DIR}/src/main.cpp ${SOURCES})
