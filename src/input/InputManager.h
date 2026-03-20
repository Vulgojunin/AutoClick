#pragma once

// Enumeração limpa e moderna para as nossas teclas (podes adicionar mais no futuro)
enum class KeyCode {
    F6,
    F7
};

class InputManager {
public:
    // Retorna 'true' se a tecla estiver a ser pressionada no momento
    static bool isKeyPressed(KeyCode key);
};