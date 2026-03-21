#include "core/actions/ClickAction.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>

void ClickAction::execute() {
#ifdef _WIN32
    // Simula o pressionamento do botão esquerdo
    INPUT inputs[2] = {};

    // 1. Pressionar (Down)
    inputs[0].type = INPUT_MOUSE;
    inputs[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    // 2. Soltar (Up)
    inputs[1].type = INPUT_MOUSE;
    inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, inputs, sizeof(INPUT));
    
    // Log de debug (pode ser removido na versão final)
    // std::cout << "[Engine] Clique disparado via SendInput" << std::endl;
#else
    // Placeholder para outros sistemas (Linux/Mac)
    std::cout << "[Engine] Clique não suportado neste SO" << std::endl;
#endif
}