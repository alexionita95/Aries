project(Utils)

file(GLOB SOURCES
    "include/*.h"
    "src/*.cpp"
)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glad glm)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME})
