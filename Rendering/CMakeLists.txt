project(Rendering)

file(GLOB SOURCES
    "include/*.h"
    "src/*.cpp"
)
add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} glad glfw glm)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)