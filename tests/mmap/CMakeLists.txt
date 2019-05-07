
file(GLOB s "../../_mmap/*.cpp")
file(GLOB h "../../_mmap/*.h")

include_directories(../../_mmap)


add_executable(test_mmap_server "main_ser.cpp"
    ${s} ${h}
    )

add_executable(test_mmap_client "main_cli.cpp"
    ${s} ${h}
    )


target_link_libraries(test_mmap_server
        #rl_mmap
        ${Boost_LIBRARIES})

target_link_libraries(test_mmap_client
        #rl_mmap
        ${Boost_LIBRARIES})

        