add_subdirectory(lib)
add_subdirectory(ui)
add_subdirectory(app)

include_directories(${CMAKE_SOURCE_DIR}/include/crypto)
include_directories(${CMAKE_SOURCE_DIR}/include/internal)
include_directories(${CMAKE_SOURCE_DIR}/include/openssl)
