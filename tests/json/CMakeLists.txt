
file(GLOB s "../../_json/*.cpp")
file(GLOB h "../../_json/*.h")

include_directories(../../_json)
include_directories(../../_public)


add_executable(test_json "main.cpp"
    ${s} ${h}
    )


target_link_libraries(test_json
        jsoncpp
        ${Boost_LIBRARIES})

        