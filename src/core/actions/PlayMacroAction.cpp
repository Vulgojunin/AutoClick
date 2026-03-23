#include "core/actions/PlayMacroAction.h"
#include "core/actions/MacroRecorder.h"

#ifdef _WIN32
#include <windows.h>
#endif

void PlayMacroAction::execute() {
#ifdef _WIN32
    const auto& events = MacroRecorder::getInstance().getMacro();
    
    if (events.empty()) return;

    for (const auto& ev : events) {
        // Pausa pelo tempo que você demorou entre uma ação e outra na vida real
        if (ev.timeElapsed > 0) {
            Sleep(ev.timeElapsed);
        }

        INPUT input = {0};
        
        // Se for um clique do mouse
        if (ev.message == WM_LBUTTONDOWN || ev.message == WM_LBUTTONUP ||
            ev.message == WM_RBUTTONDOWN || ev.message == WM_RBUTTONUP) {
            
            input.type = INPUT_MOUSE;
            // Move o mouse para a coordenada exata onde você clicou na gravação
            SetCursorPos(ev.x, ev.y); 

            if (ev.message == WM_LBUTTONDOWN) input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            else if (ev.message == WM_LBUTTONUP) input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            else if (ev.message == WM_RBUTTONDOWN) input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
            else if (ev.message == WM_RBUTTONUP) input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
            
            SendInput(1, &input, sizeof(INPUT));
        }
        // Se for uma tecla do teclado
        else if (ev.message == WM_KEYDOWN || ev.message == WM_KEYUP ||
                 ev.message == WM_SYSKEYDOWN || ev.message == WM_SYSKEYUP) {
            
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = ev.vkCode;
            if (ev.message == WM_KEYUP || ev.message == WM_SYSKEYUP) {
                input.ki.dwFlags = KEYEVENTF_KEYUP;
            }
            SendInput(1, &input, sizeof(INPUT));
        }
    }
#endif
}