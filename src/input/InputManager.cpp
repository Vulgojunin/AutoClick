#include "InputManager.h"

bool InputManager::isKeyPressed(int vKey) {
    // GetAsyncKeyState checa o estado real da tecla no Windows
    // O valor 0x8000 indica que a tecla está pressionada no momento
    return (GetAsyncKeyState(vKey) & 0x8000);
}