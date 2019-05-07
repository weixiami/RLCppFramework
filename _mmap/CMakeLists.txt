

file(GLOB s "*.cpp")
file(GLOB h "*.h")
add_library(rl_mmap ${s} ${h})


target_link_libraries(rl_mmap ${Boost_LIBRARIES})
install(FILES 
        ${PROJECT_SOURCE_DIR}/_mmap/mmap.h
        DESTINATION /usr/local/include/reckless/)
install(TARGETS rl_mmap ARCHIVE DESTINATION /usr/local/lib/)



