
file(GLOB s "../../_grpc/*.cc")
file(GLOB h "../../_grpc/*.h")

include_directories(../../_grpc)


add_executable(test_grpc_client "client.cpp"
    ${s} ${h}
    )
add_executable(test_grpc_server "server.cpp"
    ${s} ${h}
    )


target_link_libraries(test_grpc_client
        grpc++
        protobuf
        ${Boost_LIBRARIES})
target_link_libraries(test_grpc_server
        grpc++
        protobuf
        ${Boost_LIBRARIES})

        