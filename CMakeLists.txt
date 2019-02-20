# Required project information.
cmake_minimum_required (VERSION 2.8)
project (RegisterMachine)

# Set the default build mode to release if not set.
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE Release)
endif ()
message ("Build type: ${CMAKE_BUILD_TYPE}")

# Set the C general flags and flags for debug and release.
set (CMAKE_C_FLAGS "-Wall -Wextra -Wno-format -Wno-format-extra-args")
set (CMAKE_C_FLAGS_DEBUG "-g")
set (CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")
if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    message ("Compiler flags: ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG}")
elseif (${CMAKE_BUILD_TYPE} STREQUAL Release)
    message ("Compiler flags: ${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE}")
endif ()
# Set the C standard to use.
set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
message ("C standard: ${CMAKE_C_STANDARD}")

# Set the output directories.
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
message ("Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# Add the needed subdirectories
add_subdirectory (RegisterMachine)

# Setup the final executable.
add_executable (main main.c)
target_link_libraries (main RegisterMachine)
