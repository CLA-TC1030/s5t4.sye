cmake_minimum_required(VERSION 3.10)
project(Autograding)

file(GLOB SOURCES "*.cpp")

# Add executable target for tests
file(GLOB TEST_SOURCES "test/*.cpp" "*.cpp")
list(FILTER TEST_SOURCES EXCLUDE REGEX "exercise.cpp")

# Define the default parameters options

option(MAIN_EXECUTABLE "Enable Main Executable" OFF)
option(TEST_EXECUTABLE "Enable Test Executable" OFF)

option(VISUAL_STUDIO_DEBUG_NORMAL "Enable Visual Studio Debugging" OFF)
option(VISUAL_STUDIO_DEBUG_TEST "Enable Visual Studio Test Debugging" OFF)

# Add executables

if(MAIN_EXECUTABLE)
    add_executable(exercise ${SOURCES})
endif()

if(TEST_EXECUTABLE)
    add_executable(appTests ${TEST_SOURCES})
endif()

if(VISUAL_STUDIO_DEBUG_NORMAL)
    # Add executable target for visual studio debugging
    add_executable(dexercise ${SOURCES})
    set_target_properties(dexercise PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    target_compile_options(dexercise PRIVATE -g)
endif()

if(VISUAL_STUDIO_DEBUG_TEST)
    # Add executable target for visual studio test debugging
    add_executable(dexercise ${TEST_SOURCES})
    set_target_properties(dexercise PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    target_compile_options(dexercise PRIVATE -g)
endif()
