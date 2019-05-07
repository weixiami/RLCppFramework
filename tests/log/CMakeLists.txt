
file(GLOB s "../../_log/*.cpp")
file(GLOB h "../../_log/*.h")

include_directories(../../_log)
include_directories(../../_public)


add_executable(test_log "main.cpp"
    ${s} ${h}
    )


target_link_libraries(test_log
        #rl_log
        glog
        ${Boost_LIBRARIES})

        