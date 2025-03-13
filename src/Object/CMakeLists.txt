file(GLOB OBJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(Object ${OBJECT_SOURCES})

target_include_directories(Object PUBLIC ${CMAKE_SOURCE_DIR}/src/Object)
