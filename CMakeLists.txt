cmake_minimum_required(VERSION 2.8)

project(asciipaint)

file(GLOB_RECURSE ASCIIPAINT_SOURCE_FILES "src/*.c")
# file(GLOB_RECURSE ASCIIPAINT_TEST_SOURCE_FILES "test/*.c")

set (CMAKE_C_FLAGS "-g -Wall")

add_subdirectory(lib)

include_directories(lib/libobj/include)

add_executable(asciipaint ${ASCIIPAINT_SOURCE_FILES})
target_link_libraries(asciipaint libobj ncurses)

# FIND_PATH(CHECK_INCLUDE_DIRS check.h)
# FIND_LIBRARY(CHECK_LIBRARIES NAMES check)
# include_directories(${CHECK_INCLUDE_DIRS})

# add_executable(asciipaint_test ${ASCIIPAINT_TEST_SOURCE_FILES})
# target_link_libraries(asciipaint_test asciipaint ${CHECK_LIBRARIES})

