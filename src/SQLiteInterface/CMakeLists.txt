file(GLOB MENU_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

add_library(SQLiteInterface ${MENU_SOURCES})

target_include_directories(SQLiteInterface PUBLIC ${CMAKE_SOURCE_DIR}/src/SQLiteInterface)

# target_link_libraries(SQLiteInterface PUBLIC controller)