
file(GLOB s "*.cpp")
file(GLOB pb_s "*.cc")
file(GLOB h "*.h")
add_library(rl_grpc ${s} ${pb_s} ${h})


target_link_libraries(rl_grpc ${Boost_LIBRARIES})
install(FILES 
        ${PROJECT_SOURCE_DIR}/_grpc/fbs.pb.h
        DESTINATION /reckless/RCF/include/RCF)
install(TARGETS rl_grpc ARCHIVE DESTINATION /reckless/RCF/lib/)



