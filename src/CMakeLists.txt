# Set the minimum version of CMake that can be used
cmake_minimum_required(VERSION 3.28)

# Define the project
project(fluid-engine VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the executable
add_executable(fluid-engine main.cxx)

# Add external headers to target
target_include_directories(fluid-engine PUBLIC "${PROJECT_SOURCE_DIR}/include")

# Add the graphics headers to target
target_include_directories(fluid-engine PUBLIC "${PROJECT_SOURCE_DIR}/graphics")

# Add the Cocoa framework
find_library(cocoa Cocoa)
target_link_libraries(fluid-engine PUBLIC ${cocoa})

# Add the OpenGL framework
find_library(opengl OpenGL)
target_link_libraries(fluid-engine PUBLIC ${opengl})

# Add the IOKit framework
find_library(iokit IOKit)
target_link_libraries(fluid-engine PUBLIC ${iokit})

# Add the glfw library
add_library(glfw3 SHARED IMPORTED)
set_target_properties(
    glfw3
    PROPERTIES
    IMPORTED_LOCATION
    "${PROJECT_SOURCE_DIR}/lib/libglfw3.a")
target_link_libraries(fluid-engine PUBLIC glfw3)

# Add the graphics subdirectory
add_subdirectory(graphics)
target_link_libraries(fluid-engine PUBLIC graphics)
