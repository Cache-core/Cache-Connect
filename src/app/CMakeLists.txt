project(cache-connect)
add_executable(cache-connect main.cpp)
target_link_libraries(cache-connect Qt5::Widgets CacheConnect CacheConnectUI)
install(TARGETS cache-connect DESTINATION bin)
