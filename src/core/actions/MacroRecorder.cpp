#include "core/actions/MacroRecorder.h"
#include <iostream>

MacroRecorder& MacroRecorder::getInstance() {
    static MacroRecorder instance;
    return instance;
}

MacroRecorder::MacroRecorder() : m_mouseHook(nullptr), m_keyboardHook(nullptr), m_isRecording(false), m_lastEventTime(0) {}

MacroRecorder::~MacroRecorder() {
    stopRecording();
}

void MacroRecorder::startRecording() {
    if (m_isRecording) return;
    clearMacro();
    m_lastEventTime = GetTickCount();
    
#ifdef _WIN32
    // Instala os ganchos globais no Windows
    m_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, GetModuleHandle(NULL), 0);
    m_keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHookProc, GetModuleHandle(NULL), 0);
#endif
    m_isRecording = true;
}

void MacroRecorder::stopRecording() {
    if (!m_isRecording) return;
#ifdef _WIN32
    if (m_mouseHook) UnhookWindowsHookEx(m_mouseHook);
    if (m_keyboardHook) UnhookWindowsHookEx(m_keyboardHook);
    m_mouseHook = nullptr;
    m_keyboardHook = nullptr;
#endif
    m_isRecording = false;
}

void MacroRecorder::clearMacro() {
    m_events.clear();
}

const std::vector<MacroEvent>& MacroRecorder::getMacro() const {
    return m_events;
}

bool MacroRecorder::isRecording() const {
    return m_isRecording;
}

void MacroRecorder::addEvent(const MacroEvent& ev) {
    m_events.push_back(ev);
}

// =====================================================================
// CALLBACKS DO WINDOWS (Aqui a mágica da captura acontece)
// =====================================================================
#ifdef _WIN32
LRESULT CALLBACK MacroRecorder::MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        MSLLHOOKSTRUCT* mouseStruct = (MSLLHOOKSTRUCT*)lParam;
        
        // Vamos gravar apenas os cliques (ignorando movimento puro para não estourar a memória)
        if (wParam == WM_LBUTTONDOWN || wParam == WM_LBUTTONUP ||
            wParam == WM_RBUTTONDOWN || wParam == WM_RBUTTONUP) {
            
            MacroRecorder& recorder = getInstance();
            DWORD currentTime = GetTickCount();
            DWORD elapsed = currentTime - recorder.m_lastEventTime;
            recorder.m_lastEventTime = currentTime;

            MacroEvent ev;
            ev.message = wParam;
            ev.timeElapsed = elapsed;
            ev.x = mouseStruct->pt.x;
            ev.y = mouseStruct->pt.y;
            ev.vkCode = 0;

            recorder.addEvent(ev);
        }
    }
    return CallNextHookEx(getInstance().m_mouseHook, nCode, wParam, lParam);
}

LRESULT CALLBACK MacroRecorder::KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0) {
        KBDLLHOOKSTRUCT* kbdStruct = (KBDLLHOOKSTRUCT*)lParam;
        
        // Ignora a tecla F8 (vamos usá-la para iniciar/parar a gravação)
        if (kbdStruct->vkCode != VK_F8) {
            MacroRecorder& recorder = getInstance();
            DWORD currentTime = GetTickCount();
            DWORD elapsed = currentTime - recorder.m_lastEventTime;
            recorder.m_lastEventTime = currentTime;

            MacroEvent ev;
            ev.message = wParam;
            ev.timeElapsed = elapsed;
            ev.x = 0; ev.y = 0;
            ev.vkCode = kbdStruct->vkCode;

            recorder.addEvent(ev);
        }
    }
    return CallNextHookEx(getInstance().m_keyboardHook, nCode, wParam, lParam);
}
#endif