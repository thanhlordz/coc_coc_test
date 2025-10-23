cmake_minimum_required(VERSION 3.15)
project(coc_coc_test VERSION 0.1 LANGUAGES CXX)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source / include layout
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

# Collect sources
file(GLOB_RECURSE PROJECT_SOURCES
    "${SRC_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Include headers
target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

# Useful warnings
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()