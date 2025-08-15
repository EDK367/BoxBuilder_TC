cmake_minimum_required(VERSION 3.16)

project(BoxBuilderTC VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BoxBuilderTC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        utils/minBoardSize.cpp
        utils/minBoardSize.h
        viewplay.h viewplay.cpp viewplay.ui
        models/players.h models/players.cpp
        rules/gamerules.h rules/gamerules.cpp
        models/node.h models/node.cpp
        models/nodeboard.h models/nodeboard.cpp
        utils/clickgraphics.h utils/clickgraphics.cpp
        methods/randomnative.h methods/randomnative.cpp
        methods/arraymess.h methods/arraymess.cpp
        methods/fifo.h methods/fifo.cpp
        models/nodofifo.h models/nodofifo.cpp
        models/nodelinked.h models/nodelinked.cpp
        methods/nodevector.h methods/nodevector.cpp
        utils/boxgraphics.h utils/boxgraphics.cpp
        models/enum/powermanager.h models/enum/powermanager.cpp
        methods/probability.h methods/probability.cpp



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET BoxBuilderTC APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BoxBuilderTC SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BoxBuilderTC
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BoxBuilderTC PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BoxBuilderTC)
endif()
set_target_properties(BoxBuilderTC PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BoxBuilderTC
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BoxBuilderTC)
endif()
