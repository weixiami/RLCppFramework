
file(GLOB s "*.cpp")
file(GLOB h "*.h")
add_library(rl_async ${s} ${h})


target_link_libraries(rl_async ${Boost_LIBRARIES})
install(FILES 
        ${PROJECT_SOURCE_DIR}/_async/async.h
        ${PROJECT_SOURCE_DIR}/_async/thread_pool.h
        ${PROJECT_SOURCE_DIR}/_async/thread.h
        ${PROJECT_SOURCE_DIR}/_async/timer.h 
        DESTINATION /reckless/RCF/include/RCF/)
install(TARGETS rl_async ARCHIVE DESTINATION /reckless/RCF/lib/)



