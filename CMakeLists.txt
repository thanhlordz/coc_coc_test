cmake_minimum_required(VERSION 3.15)

project(coc_coc_test)

set(EXECUTABLE_NAME "CocCoc_T")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/app)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(${EXECUTABLE_NAME} ${SOURCES})

target_include_directories(${EXECUTABLE_NAME} 
    PRIVATE 
        ${CMAKE_SOURCE_DIR}/include
)

target_compile_definitions(${EXECUTABLE_NAME} 
    PRIVATE 
        COMMANDS_PATH="${CMAKE_SOURCE_DIR}/input_file/commands.txt"
)