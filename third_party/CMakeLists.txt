set(CMAKE_FOLDER third_party)
if(NOT ${USE_QT})
add_subdirectory(glfw)
endif()
add_subdirectory(glm)
add_subdirectory(glad)
add_subdirectory(stb)


