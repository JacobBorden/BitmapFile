cmake_minimum_required(VERSION 3.0.0)
project(bitmap VERSION 1.0.0)

include(CTest)
enable_testing()

include_directories(src)

add_library(bitmapfile STATIC src/bitmap_file.cpp)
add_executable(testexe main.cpp)
target_link_libraries(testexe bitmapfile)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set( CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include (Cpack)