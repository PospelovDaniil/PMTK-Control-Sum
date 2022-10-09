cmake_minimum_required(VERSION 3.5)

project(pmtk LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(CMAKE_CURRENT_BINARY_DIR/src/)
add_executable(pmtk main.cpp
                    src/pmtk.h)

install(TARGETS pmtk
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
