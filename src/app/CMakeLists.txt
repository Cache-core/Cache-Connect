project(cache-connect)
add_executable(cacheconnect main.cpp)
target_link_libraries(cacheconnect Qt5::Widgets CacheConnect CacheConnectUI)
install(TARGETS cacheconnect DESTINATION bin)
