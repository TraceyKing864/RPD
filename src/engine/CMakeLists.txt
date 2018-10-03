file(GLOB EngSources *.cpp) 
add_library(eng ${EngSources})
target_link_libraries(eng PUBLIC the_game)
