cmake_minimum_required(VERSION 3.0.0)
project(raytracing VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(raytracing main.cpp)

target_include_directories(raytracing PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
