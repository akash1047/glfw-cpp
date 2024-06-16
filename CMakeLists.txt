cmake_minimum_required(VERSION 3.28)

project(glfw_cpp)

add_subdirectory(external/glfw)

add_library(${PROJECT_NAME} STATIC src/glfw.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE external/glfw/include)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
