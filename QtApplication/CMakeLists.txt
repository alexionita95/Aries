project(QtApplication VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()
find_package(OpenGL REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets OpenGL OpenGLWidgets REQUIRED)

file(GLOB SOURCES
    "*.h"
    "*.cpp"
        "*.ui"
)
#set(PROJECT_SOURCES
#        main.cpp
#        MainWindow.cpp
#       MainWindow.h
#        Renderer.h
#        Renderer.cpp
#        MainWindow.ui
#        glad/glad.h
#        glad/glad.c
#)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
        MANUAL_FINALIZATION
        ${SOURCES}
    )
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED
            ${SOURCES}
        )
    else()
        add_executable(${PROJECT_NAME}
            ${SOURCES}
        )
    endif()
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGL Qt${QT_VERSION_MAJOR}::OpenGLWidgets Rendering Physics)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
install(TARGETS ${PROJECT_NAME})
