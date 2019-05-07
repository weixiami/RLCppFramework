
file(GLOB s "../../_http/*.cpp")
file(GLOB h "../../_http/*.h")

include_directories(../../_http)


add_executable(test_http "main.cpp"
    ${s} ${h}
    )


target_link_libraries(test_http
        curl
        ${Boost_LIBRARIES})

        