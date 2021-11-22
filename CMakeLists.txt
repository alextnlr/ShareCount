cmake_minimum_required(VERSION 3.20)
project(sharecount)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)


add_executable(sharecount
        main.cpp
        MainWindow.cpp
        Compte.cpp
        FabriqueIdentifiant.cpp
        GestionnaireCompte.cpp
        MainWindow.h ShareCount.cpp ShareCount.h ObserverPattern.h Compte.h GestionnaireCompte.h FabriqueIdentifiant.h)


target_link_libraries(sharecount
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )