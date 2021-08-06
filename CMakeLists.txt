cmake_minimum_required(VERSION 3.5)

project(weather LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

set(TS_FILES weather_ru_RU.ts)

set(PROJECT_SOURCES
        main.cxx
        MainWindow.cxx
        MainWindow.h
        MainWindow.ui
        APIManager.cxx
        APIManager.h
        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(weather
        ${PROJECT_SOURCES}
    )

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(weather SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(weather
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()
find_package(Qt5 COMPONENTS Network REQUIRED)
target_link_libraries(weather PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(weather PRIVATE Qt${QT_VERSION_MAJOR}::Network)
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK")
include(CPack)
