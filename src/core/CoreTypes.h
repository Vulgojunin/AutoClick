#ifndef CORETYPES_H
#define CORETYPES_H

#ifdef _WIN32
#include <windows.h>
#endif

// Adicionamos o "Macro" na lista de ações possíveis
enum class ActionType {
    None,
    LeftClick,
    RightClick,
    Macro 
};

enum class StrategyType {
    None,
    Fixed,
    Jitter
};

// Estrutura para salvar cada passo da Macro
struct MacroEvent {
    int message;       // Ex: WM_LBUTTONDOWN, WM_KEYDOWN
    unsigned long timeElapsed; // Tempo de espera antes de executar isso (em ms)
    int x, y;          // Posição do mouse (se for evento de mouse)
    unsigned long vkCode;      // Código da tecla (se for evento de teclado)
};

#endif // CORETYPES_H