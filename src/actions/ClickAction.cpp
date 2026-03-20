#include "ClickAction.h"
#include <windows.h> // Será removido na Fase 3 (Lei da Antecipação)

ClickAction::ClickAction(MouseButton b, ClickType t) 
    : button(b), type(t) {}

void ClickAction::execute() {
    INPUT input = {0};
    input.type = INPUT_MOUSE;

    // Define os flags do Windows com base no botão escolhido
    DWORD downFlag, upFlag;
    switch (button) {
        case MouseButton::Right:
            downFlag = MOUSEEVENTF_RIGHTDOWN;
            upFlag = MOUSEEVENTF_RIGHTUP;
            break;
        case MouseButton::Middle:
            downFlag = MOUSEEVENTF_MIDDLEDOWN;
            upFlag = MOUSEEVENTF_MIDDLEUP;
            break;
        case MouseButton::Left:
        default:
            downFlag = MOUSEEVENTF_LEFTDOWN;
            upFlag = MOUSEEVENTF_LEFTUP;
            break;
    }

    // Executa o clique físico (Lógica básica)
    input.mi.dwFlags = downFlag;
    SendInput(1, &input, sizeof(INPUT));

    if (type != ClickType::Hold) {
        input.mi.dwFlags = upFlag;
        SendInput(1, &input, sizeof(INPUT));
    }
}