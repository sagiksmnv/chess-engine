cmake_minimum_required(VERSION 3.25)
project(chessEngine VERSION 0.1.0 LANGUAGES C CXX)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(CMAKE_CXX_STANDARD 17)

include_directories(/opt/homebrew/include)
include_directories(include)
include_directories(src)
set(src src/main.cpp)
set(include include/config.hpp)

add_executable(chessEngine  ${src}
                            ${include})

find_package(GLM REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

target_link_libraries(chessEngine glfw)
target_link_libraries(chessEngine GLEW::GLEW)