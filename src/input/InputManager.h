#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <windows.h>

class InputManager {
public:
    // Usamos 'int' para representar as teclas do Windows (VK_F6, VK_SPACE, etc)
    static bool isKeyPressed(int vKey);
};

#endif