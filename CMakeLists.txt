cmake_minimum_required(VERSION 3.27)
project(weather_forecaster
        VERSION 1.0
        DESCRIPTION "С++ weather forecast console application"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

if (WIN32) # Install dlls in the same directory as the executable on Windows
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()

add_subdirectory(bin)
add_subdirectory(lib)
