cmake_minimum_required (VERSION 3.0)
project (RPD)


# set standards at the project level
set(CMAKE_CXX_STANDARD 17)

# add CMake modules from their folder
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# put the binary in the build folder 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)

# Use the module for finding and linking SDL2 stuff
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(RPD ${SDL2_INCLUDE_DIRS} ${SDL_IMAGE_INCLUDE_DIRS})

#go to src
add_subdirectory(src)
