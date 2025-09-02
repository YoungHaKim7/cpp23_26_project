cmake_minimum_required(VERSION 4.0)

get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Object library for the math module
add_library(project_modules OBJECT)

target_sources(project_modules
    PUBLIC
        FILE_SET cxx_modules TYPE CXX_MODULES FILES
            src/modules/math_stuff.ixx
    # PRIVATE
        # src/modules/math.cpp
)

target_compile_options(project_modules PRIVATE
    -Wall
    -Wextra
    -pedantic
    -pedantic-errors
    -pthread
    -ggdb
    -fmodules-ts
)

# Main executable
add_executable(${ProjectId} src/main.cpp)

target_link_libraries(${ProjectId} PRIVATE project_modules)

target_link_options(${ProjectId} PRIVATE
    -pthread
    -lm
)

# Output directories
set_target_properties(${ProjectId} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)
set_target_properties(project_modules PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/target
)
