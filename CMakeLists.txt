cmake_minimum_required(VERSION 3.20)
project(Aries)

add_subdirectory(third_party)
add_subdirectory(Rendering)
add_subdirectory(DemoApplication)
install(DIRECTORY resources DESTINATION bin)