cmake_minimum_required(VERSION 4.0)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Common compile flags
add_compile_options(
    -pedantic
    -pthread
    -pedantic-errors
    -lm
    -Wall
    -Wextra
    -ggdb
    -fmodules-ts
)

# Object library for modules
add_library(project_modules OBJECT)

# Tell CMake these are C++ modules
target_sources(project_modules
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            src/modules/math.ixx
)

# Main executable
add_executable(${ProjectId} 
    src/main.cpp
    src/modules/math.cpp
)
target_link_libraries(${ProjectId} PRIVATE project_modules)

# Link options
target_link_options(${ProjectId} PRIVATE -pthread -lm -fmodules-ts)

# Output directories
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)
set_target_properties(project_modules PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)

