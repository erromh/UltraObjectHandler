file(GLOB CONTROLLER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(controller ${CONTROLLER_SOURCES})

target_include_directories(controller PUBLIC ${CMAKE_SOURCE_DIR}/src/Controller)

target_link_libraries(controller PUBLIC DataManager Menu)