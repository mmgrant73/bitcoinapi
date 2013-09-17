add_executable(examplecalls examplecalls.cpp)
target_link_libraries(examplecalls bitcoin)

add_executable(getmininginfo getmininginfo.cpp)
target_link_libraries(getmininginfo bitcoin)

add_executable(getbalance getbalance.cpp)
target_link_libraries(getbalance bitcoin)

add_executable(getpeerinfo getpeerinfo.cpp)
target_link_libraries(getpeerinfo bitcoin)

add_executable(getnewaddress getnewaddress.cpp)
target_link_libraries(getnewaddress bitcoin)

add_executable(getdifficulty getdifficulty.cpp)
target_link_libraries(getdifficulty bitcoin)
