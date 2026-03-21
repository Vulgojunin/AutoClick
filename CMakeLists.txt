cmake_minimum_required(VERSION 3.16)
project(Autoclicker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ativa o processamento automático do Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Cria o executável
add_executable(Autoclicker)

# Registro explícito - O AppCommand.h agora está em use_cases
target_sources(Autoclicker PRIVATE
    src/main.cpp

    # UI
    ui/MainWindow.h
    ui/MainWindow.cpp
    ui/MainWindow.ui

    # Controller
    src/controller/Controller.h
    src/controller/Controller.cpp

    # Application / Use Cases
    src/application/use_cases/AppTypes.h
    src/application/use_cases/AppCommand.h
    src/application/use_cases/StartClickingUseCase.h
    src/application/use_cases/StartClickingUseCase.cpp
    src/application/use_cases/StopClickingUseCase.h
    src/application/use_cases/StopClickingUseCase.cpp

    # Core
    src/core/engine/Engine.h
    src/core/engine/Engine.cpp
    src/core/engine/ExecutionNotifier.h
    src/core/interfaces/IAction.h
    src/core/interfaces/IStrategy.h
    src/core/interfaces/IControllerObserver.h
    src/core/registry/ActionRegistry.h
    src/core/registry/StrategyRegistry.h
    src/core/actions/ClickAction.h
    src/core/actions/ClickAction.cpp
    src/core/strategies/FixedStrategy.h
    src/core/strategies/JitterStrategy.h
)

# Diretórios de include (Mantendo o isolamento na src)
target_include_directories(Autoclicker PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)

target_link_libraries(Autoclicker PRIVATE 
    Qt6::Widgets 
    User32
)