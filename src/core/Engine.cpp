#include "Engine.h"
#include <chrono>

void Engine::start() {
    if (m_running) return;
    m_running = true;
    // Cria uma thread para clicar sem travar a interface
    m_thread = std::thread(&Engine::loop, this);
}

void Engine::stop() {
    m_running = false;
    if (m_thread.joinable()) {
        m_thread.join(); // Espera a thread terminar com segurança
    }
}

void Engine::loop() {
    while (m_running) {
        performClick();
        // Espera o tempo definido pelo usuário
        std::this_thread::sleep_for(std::chrono::milliseconds(m_delay.load()));
    }
}

void Engine::performClick() {
    INPUT input = {0};
    input.type = INPUT_MOUSE;

    // 1. Pressiona o botão esquerdo
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    // 2. Solta o botão esquerdo
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
}