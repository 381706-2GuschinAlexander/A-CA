file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_executable(${d_heap_sort_main} ${srcs} ${hdrs}) 
target_link_libraries(${d_heap_sort_main} ${d_heap_sort_lib})


