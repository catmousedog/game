cmake_minimum_required(VERSION 3.10)
project(Game)

set(CMAKE_CXX_STANDARD 23)

find_package(SFML 3 COMPONENTS Graphics Window System)
find_package(yaml-cpp REQUIRED)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(game ${SOURCES})
target_link_libraries(game PRIVATE sfml-graphics sfml-window sfml-system yaml-cpp)
