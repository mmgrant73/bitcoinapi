file(GLOB_RECURSE bitcoin_source *.c*)
file(GLOB bitcoin_header *.h)
file(GLOB jsonrpc_header jsonrpc/*.h)
file(GLOB connector_header jsonrpc/connectors/*.h)
file(GLOB jsoncpp_header jsonrpc/json/*.h)

add_library(bitcoin SHARED ${bitcoin_source})
add_library(bitcoinStatic STATIC ${bitcoin_source})

set_target_properties(bitcoinStatic PROPERTIES OUTPUT_NAME bitcoin)

set(VERSION_STRING ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}) 
set_target_properties(bitcoin bitcoinStatic PROPERTIES VERSION "${VERSION_STRING}" SOVERSION "${VERSION_MAJOR}")


target_link_libraries(bitcoin ${CURL_LIBRARIES})
target_link_libraries(bitcoinStatic ${CURL_LIBRARIES})

install(FILES ${bitcoin_header} DESTINATION include/bitcoin) 
install(FILES ${jsonrpc_header} DESTINATION include/bitcoin/jsonrpc) 
install(FILES ${connector_header} DESTINATION include/bitcoin/jsonrpc/connectors)
install(FILES ${jsoncpp_header} DESTINATION include/bitcoin/jsonrpc/json) 

install(TARGETS bitcoin bitcoinStatic LIBRARY DESTINATION lib
                      ARCHIVE DESTINATION lib
                      RUNTIME DESTINATION bin)

