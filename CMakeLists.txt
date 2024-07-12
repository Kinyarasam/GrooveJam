cmake_minimum_required(VERSION 3.0)
project(GrooveJam)

# Set Compiler Flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra -pedantic -std=gnu89 -Iinclude")

# Directories
set(SRC_DIR src)
set(BUILD_DIR build)
set(BIN_DIR bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source Files
file(GLOB SRC_FILES ${SRC_DIR}/*.c)

# Output executable
add_executable(GrooveJam ${SRC_FILES} include)

# Output directory
set_target_properties(GrooveJam PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}"
)
