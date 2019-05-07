

file(GLOB s "*.cpp")
file(GLOB h "*.h")
add_library(rl_log ${s} ${h})

include_directories(../_public)

target_link_libraries(rl_log
        glog
        ${Boost_LIBRARIES})
        
install(FILES 
        ${PROJECT_SOURCE_DIR}/_log/log.h
        DESTINATION /usr/local/include/reckless/)
install(TARGETS rl_log ARCHIVE DESTINATION /usr/local/lib/)










