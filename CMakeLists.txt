cmake_minimum_required(VERSION 3.0.0)
project(bitmap VERSION 1.0.0)

include(CTest)
enable_testing()

add_library(bitmapfile STATIC src/bitmap_file.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set( CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include (Cpack)