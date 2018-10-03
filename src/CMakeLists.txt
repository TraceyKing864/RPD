add_subdirectory(engine)

# create the executable and link everything accordingly
add_executable(the_game main.cpp) 
target_link_libraries(the_game eng SDL2 SDL2_image)
