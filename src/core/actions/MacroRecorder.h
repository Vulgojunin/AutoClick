#ifndef MACRORECORDER_H
#define MACRORECORDER_H

#include <vector>
#include "core/CoreTypes.h"

class MacroRecorder {
public:
    // Acessa a única instância do gravador
    static MacroRecorder& getInstance();

    void startRecording();
    void stopRecording();
    void clearMacro();
    
    const std::vector<MacroEvent>& getMacro() const;
    bool isRecording() const;

private:
    MacroRecorder();
    ~MacroRecorder();

    // Funções estáticas obrigatórias para a API do Windows
    static LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);

    void addEvent(const MacroEvent& ev);

#ifdef _WIN32
    HHOOK m_mouseHook;
    HHOOK m_keyboardHook;
#endif

    bool m_isRecording;
    std::vector<MacroEvent> m_events;
    unsigned long m_lastEventTime;
};

#endif // MACRORECORDER_H