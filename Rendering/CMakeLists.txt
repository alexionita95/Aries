project(Rendering)

file(GLOB_RECURSE SOURCES
    "include/*.h"
    "src/*.cpp"
)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glfw glad glm stb)
target_include_directories(${PROJECT_NAME} PUBLIC include)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
install(TARGETS ${PROJECT_NAME})
