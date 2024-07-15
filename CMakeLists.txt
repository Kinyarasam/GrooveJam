cmake_minimum_required(VERSION 3.10)
project(GrooveJam)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Directories
set(SRC_DIR src)
set(BUILD_DIR build)
set(BIN_DIR bin)

# Include directories
include_directories(/usr/local/opt/libao/include /usr/local/opt/mpg123/include include)

# Source files
file(GLOB SRC_FILES ${SRC_DIR}/*.c)

# Link directories
link_directories(/usr/local/opt/libao/lib /usr/local/opt/mpg123/lib)

# Add the executable
add_executable(GrooveWave ${SRC_FILES})

# Link the libraries
target_link_libraries(GrooveWave ao mpg123)

# Output directory
set_target_properties(GrooveWave PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}"
    ARCHIVE_OUTPUT_DIRECTORY "${BUILD_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${BUILD_DIR}"
)
