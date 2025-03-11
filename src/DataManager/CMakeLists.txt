file(GLOB MANAGER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(DataManager ${MANAGER_SOURCES})

target_include_directories(DataManager PUBLIC ${CMAKE_SOURCE_DIR}/src/DataManager)

target_link_libraries(DataManager PUBLIC SQLiteInterface controller)