
file(GLOB s "../../_async/*.cpp")
file(GLOB h "../../_async/*.h")

include_directories(../../_async)


add_executable(test_async "main.cpp"
    ${s} ${h}
    )


target_link_libraries(test_async
        #rl_async
        ${Boost_LIBRARIES})



