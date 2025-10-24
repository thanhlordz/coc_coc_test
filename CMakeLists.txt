cmake_minimum_required(VERSION 3.15)
project(coc_coc_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/app)

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
set(APP_SOURCES ${SRC_FILES})
list(REMOVE_ITEM APP_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

set(EXECUTABLE_NAME "CocCoc_T")
add_executable(${EXECUTABLE_NAME} src/main.cpp ${APP_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_compile_definitions(${EXECUTABLE_NAME}
    PRIVATE COMMANDS_PATH="${CMAKE_SOURCE_DIR}/input_file/commands.txt")

add_subdirectory(test_framework/googletest)

enable_testing()
file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")

set(TEST_EXECUTABLE_NAME "test_runner")
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SOURCES} ${APP_SOURCES})
target_include_directories(${TEST_EXECUTABLE_NAME} PRIVATE include)
target_link_libraries(${TEST_EXECUTABLE_NAME} PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(${TEST_EXECUTABLE_NAME})
