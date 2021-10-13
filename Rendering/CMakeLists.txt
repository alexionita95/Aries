project(Rendering)

file(GLOB SOURCES
    "include/*.h"
    "src/*.cpp"
)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} glad glm Utils stb)
target_include_directories(${PROJECT_NAME} PUBLIC include)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

message(${CMAKE_CXX_COMPILER_ID})
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # G++
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    # MSVC
    target_compile_options(${PROJECT_NAME} PRIVATE /EHsc /MTd /W2 /c)
    # Set the DLLEXPORT variable to export symbols
    target_compile_definitions(${PROJECT_NAME} PRIVATE WIN_EXPORT)
endif()

install(TARGETS ${PROJECT_NAME})
