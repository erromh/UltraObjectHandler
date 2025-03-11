file(GLOB MENU_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(Menu ${MENU_SOURCES})

target_include_directories(Menu PUBLIC ${CMAKE_SOURCE_DIR}/src/Menu)

target_link_libraries(Menu PUBLIC controller)