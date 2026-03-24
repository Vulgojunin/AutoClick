cmake_minimum_required(VERSION 3.16)
project(Autoclicker VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ativa o processamento automático do Qt (MOC, RCC e UIC)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Busca o pacote do Qt6
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Cria o executável
add_executable(Autoclicker)

# Registro de todos os arquivos do projeto
target_sources(Autoclicker PRIVATE
    src/main.cpp

    # Camada de Interface (UI)
    ui/MainWindow.h
    ui/MainWindow.cpp
    ui/MainWindow.ui

    # Camada de Controle
    src/controller/Controller.h
    src/controller/Controller.cpp

    # Camada de Aplicação (Regras de Negócio)
    src/application/use_cases/AppTypes.h
    src/application/use_cases/AppCommand.h
    src/application/use_cases/StartClickingUseCase.h
    src/application/use_cases/StartClickingUseCase.cpp
    src/application/use_cases/StopClickingUseCase.h
    src/application/use_cases/StopClickingUseCase.cpp

    # Camada Core (Motor e Lógica Base)
    src/core/engine/Engine.h
    src/core/engine/Engine.cpp
    src/core/engine/ExecutionNotifier.h
    src/core/interfaces/IAction.h
    src/core/interfaces/IStrategy.h
    src/core/interfaces/IControllerObserver.h
    src/core/registry/ActionRegistry.h
    src/core/registry/StrategyRegistry.h
    
    # Ações e Estratégias de Clique
    src/core/actions/ClickAction.h
    src/core/actions/ClickAction.cpp
    src/core/strategies/FixedStrategy.h
    src/core/strategies/JitterStrategy.h
    
    # Tipos de Dados Internos
    src/core/CoreTypes.h
)

# Configura os diretórios de busca (Includes)
target_include_directories(Autoclicker PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)

# Linka as bibliotecas necessárias
target_link_libraries(Autoclicker PRIVATE 
    Qt6::Widgets 
    User32  # Necessário para as Hotkeys do Windows funcionarem
)

# ====================================================================
# SISTEMA DE CÓPIA DE RECURSOS (DESIGN E ÍCONES)
# Isso garante que o visual carregue na pasta do .exe
# ====================================================================

# Copia o arquivo de estilos (CSS)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/style.qss")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/style.qss" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
    message(STATUS "CMake: style.qss preparado para copia.")
endif()

# Copia a pasta de ícones e molduras
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/icons")
    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/icons" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
    message(STATUS "CMake: Pasta icons preparada para copia.")
endif()