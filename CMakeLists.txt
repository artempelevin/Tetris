project(Tetris LANGUAGES CXX)
cmake_minimum_required(VERSION 3.1)

set(CMAKE_SOURSE_DIR srs/)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_library(SDL2_LIBRARY SDL2)
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_definitions(-DWINDOWS)
endif ()
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_definitions(-DLINUX)
endif ()


include_directories(${CMAKE_SOURSE_DIR})
aux_source_directory(${CMAKE_SOURSE_DIR} SOURSES)

add_executable(${PROJECT_NAME} ${SOURSES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
