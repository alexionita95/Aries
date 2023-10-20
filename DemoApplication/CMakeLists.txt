project(DemoApplication)
file(GLOB_RECURSE SOURCES
    "include/*.h"
    "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})
if(CMAKE_BUILD_TYPE STREQUAL "Release")
set_target_properties(${PROJECT_NAME} PROPERTIES 
    LINK_FLAGS "/ENTRY:mainCRTStartup /SUBSYSTEM:WINDOWS")
    endif()
target_link_libraries(${PROJECT_NAME} Rendering)
target_include_directories(${PROJECT_NAME} PUBLIC include)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
install(TARGETS ${PROJECT_NAME})
