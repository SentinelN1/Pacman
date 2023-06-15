cmake_minimum_required(VERSION 3.25)
project(Pacman)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(Pacman Entity.h main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR "D:/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories("D:/SFML-2.5.1/include")
target_link_libraries(Pacman sfml-system sfml-window sfml-graphics sfml-audio)
