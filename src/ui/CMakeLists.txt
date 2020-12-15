set(CacheConnectUILibrary_SRS
    cacheconnectwindow.cpp
    messenger.cpp
    messagelist.cpp
    pendingtransfers.cpp
    runningtransfers.cpp
    uimanager.cpp
    userlist.cpp
)

set(CacheConnectUILibrary_HEADERS
    cacheconnectwindow.h
    messenger.h
    messagelist.h
    pendingtransfers.h
    runningtransfers.h
    uimanager.h
    userlist.h
)

set(CacheConnectUILibrary_RCC
    window.qrc
)

add_library(CacheConnectUI SHARED ${CacheConnectUILibrary_SRS} ${CacheConnectUILibrary_RCC})
target_link_libraries(CacheConnectUI Qt5::Core Qt5::Widgets Qt5::Quick Qt5::QuickControls2 CacheConnect)
install(TARGETS CacheConnectUI LIBRARY DESTINATION lib)
install(FILES ${CacheConnectUILibrary_HEADERS} DESTINATION include/cacheconnect/ui)
target_include_directories(CacheConnectUI SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/src/ui)
