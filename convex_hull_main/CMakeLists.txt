file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${convex_hull_main} ${srcs} ${hdrs}) 
target_link_libraries(${convex_hull_main} ${convex_hull_lib})


