cmake_minimum_required(VERSION 3.22)
project(GL)

set(CMAKE_CXX_STANDARD 14)
set(GLEW_STATIC 1)
set(GLFW_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLFW)
set(GLEW_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/GLEW)

add_executable(GL src/main.cpp)

include_directories(
    ${GLFW_ROOT_DIR}/include ${GLEW_ROOT_DIR}/include
)

find_library(glfw3_lib ${GLFW_ROOT_DIR}/lib)
find_library(GLEW_LIBRARY ${GLEW_ROOT_DIR}/lib)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

target_link_libraries(${PROJECT_NAME} PRIVATE ${glfw3_lib} ${GLEW_LIBRARY})

if (APPLE)
    find_library(cocoa_lib Cocoa)
    find_library(iokit_lib IOKit)
    set(frameworks
            ${cocoa_lib}
            ${iokit_lib}
            )
    target_link_libraries(${PROJECT_NAME} PRIVATE ${frameworks} "-framework OpenGL")
endif()
