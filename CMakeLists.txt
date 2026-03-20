cmake_minimum_required(VERSION 3.16)
project(Autoclicker VERSION 1.0 LANGUAGES CXX)

include_directories(src)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

file(GLOB_RECURSE SOURCES "src/*.cpp" "ui/*.cpp" "main.cpp")

add_executable(Autoclicker ${SOURCES})

target_include_directories(Autoclicker PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/core/interfaces"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/actions/interfaces"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/strategies/interfaces"
    "${CMAKE_CURRENT_SOURCE_DIR}/external"
)

target_link_libraries(Autoclicker PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)