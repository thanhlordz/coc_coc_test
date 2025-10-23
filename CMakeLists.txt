cmake_minimum_required(VERSION 3.15)
project(coc_coc_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE PROJECT_SOURCES
    "${SRC_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${INC_DIR})

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wshadow)
endif()

# If commands.txt exists in source tree, copy it to the build dir so the exe can find it.
if(EXISTS "${CMAKE_SOURCE_DIR}/commands.txt")
    file(COPY "${CMAKE_SOURCE_DIR}/commands.txt" DESTINATION "${CMAKE_BINARY_DIR}")
endif()

# Convenience target to run the built executable
add_custom_target(run
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_COMMAND} -E echo "Running ${PROJECT_NAME}..."
    COMMAND $<TARGET_FILE:${PROJECT_NAME}>
    USES_TERMINAL
)