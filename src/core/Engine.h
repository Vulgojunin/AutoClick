#ifndef ENGINE_H
#define ENGINE_H

#include <atomic>
#include <thread>
#include <windows.h> // Para o SendInput

class Engine {
public:
    Engine() : m_delay(100), m_running(false) {}
    ~Engine() { stop(); }

    void start();
    void stop();
    void setDelay(int ms) { m_delay = ms; }

private:
    void loop();          // A função que vai rodar na thread
    void performClick();  // O clique real no Windows

    std::atomic<int> m_delay;
    std::atomic<bool> m_running;
    std::thread m_thread; // O "trabalhador" de fundo
};

#endif