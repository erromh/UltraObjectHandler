cmake_minimum_required (VERSION 3.8)
project (UltraObjectHandler LANGUAGES CXX C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DPROJECT_ROOT_DIR=\"${CMAKE_SOURCE_DIR}\")

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Welcome to Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Welcome to win32")
else()
    message(STATUS "This is ${CMAKE_SYSTEM_NAME} speaking.")
endif()

include_directories(${CMAKE_SOURCE_DIR}/src/Object) 
# include_directories(${CMAKE_SOURCE_DIR}/src/SQLiteHeader) 

add_subdirectory(src)
add_executable(UltraObjectHandler main.cpp)

target_link_libraries(UltraObjectHandler
    PUBLIC
        controller
        Menu
        DataManager
        SQLiteInterface
    )