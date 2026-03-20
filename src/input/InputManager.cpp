#include "InputManager.h"
#include <windows.h> // Oculto aqui dentro! Ninguém mais no projeto precisa disto.

bool InputManager::isKeyPressed(KeyCode key) {
    int vKey = 0;

    // Traduz a nossa tecla limpa para o código feio do Windows
    switch (key) {
        case KeyCode::F6: 
            vKey = VK_F6; 
            break;
        case KeyCode::F7: 
            vKey = VK_F7; 
            break;
    }

    // Verifica o estado físico da tecla no hardware
    return (GetAsyncKeyState(vKey) & 0x8000) != 0;
}