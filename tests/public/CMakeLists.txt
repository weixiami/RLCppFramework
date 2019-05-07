
file(GLOB s "../../_public/*.cpp")
file(GLOB h "../../_public/*.h")

include_directories(../../_public)


add_executable(test_public "main.cpp"
    ${s} ${h}
    )


target_link_libraries(test_public
        ${Boost_LIBRARIES})

