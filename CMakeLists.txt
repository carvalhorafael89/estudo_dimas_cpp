cmake_minimum_required(VERSION 3.5)

project(dimas_cpp_qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6Sql REQUIRED)


set(PROJECT_SOURCES
    #headers
    model/Produto.h
    model/Cliente.h
    model/Pessoa.h
    #model/Vendedor.h
    view/menu_produto.h
    view/menu_principal.h
    view/menu_cliente.h
    control/daoproduto.h
    control/daocliente.h
    control/conexao.h
#----------------------------#
    #sources
    model/Produto.cpp
    model/Cliente.cpp
    model/Pessoa.cpp
    #model/Vendedor.cpp
    view/menu_produto.cpp
    view/menu_principal.cpp
    view/menu_cliente.cpp
    control/conexao.cpp
    control/daoproduto.cpp
    control/daocliente.cpp
    main.cpp
#----------------------------#
    #.ui (forms)
    view/menu_principal.ui
    view/menu_produto.ui
    view/menu_cliente.ui

)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(dimas_cpp_qt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET dimas_cpp_qt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(dimas_cpp_qt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(dimas_cpp_qt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(dimas_cpp_qt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Sql Qt6::Core)

set_target_properties(dimas_cpp_qt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS dimas_cpp_qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(dimas_cpp_qt)
endif()
