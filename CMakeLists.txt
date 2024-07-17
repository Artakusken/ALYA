cmake_minimum_required(VERSION 3.26)
project(ALYA)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#link_directories("library/")
#add_subdirectory("library/")
include_directories("library/")

add_library(alya SHARED library/alya.cpp)

add_executable(ALYA main.cpp)

target_link_libraries(ALYA alya)