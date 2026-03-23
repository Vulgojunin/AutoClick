#include "core/actions/ClickAction.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

// Inicializa a variável membro com o tipo recebido da Factory (ActionRegistry)
ClickAction::ClickAction(ActionType type) : m_type(type) {}

void ClickAction::execute() {
#ifdef _WIN32
    INPUT inputs[2] = {};

    inputs[0].type = INPUT_MOUSE;
    inputs[1].type = INPUT_MOUSE;

    // Lógica condicional para definir o botão correto na API do Windows
    if (m_type == ActionType::RightClick) {
        // 1. Pressionar (Down) - Direito
        inputs[0].mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        // 2. Soltar (Up) - Direito
        inputs[1].mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    } else {
        // Default: 1. Pressionar (Down) - Esquerdo
        inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        // Default: 2. Soltar (Up) - Esquerdo
        inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    }

    SendInput(2, inputs, sizeof(INPUT));
    
#else
    // Placeholder para outros sistemas (Linux/Mac)
    std::cout << "[Engine] Clique não suportado neste SO" << std::endl;
#endif
}