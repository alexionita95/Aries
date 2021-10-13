project(stb)
file(GLOB SOURCES
    file(GLOB SOURCES
    "include/*.h"
)
)
add_library(${PROJECT_NAME} INTERFACE ${SOURCES})
target_include_directories(${PROJECT_NAME} INTERFACE include)
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS ${PROJECT_NAME} 
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)