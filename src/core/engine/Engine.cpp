#include "core/engine/Engine.h"

Engine::Engine() : m_running(false), m_isInfinite(true), m_repeatTimes(0) {}

Engine::~Engine() {
    stop();
}

void Engine::setAction(std::unique_ptr<IAction> action) {
    m_action = std::move(action);
}

void Engine::setStrategy(std::unique_ptr<IStrategy> strategy) {
    m_strategy = std::move(strategy);
}

void Engine::setRepeatConfig(bool isInfinite, int repeatTimes) {
    m_isInfinite = isInfinite;
    m_repeatTimes = repeatTimes;
}

void Engine::setAutoStopCallback(std::function<void()> callback) {
    m_autoStopCallback = callback;
}

void Engine::start() {
    if (m_running) return;

    // Limpa a thread anterior se ela ainda existir (evita crash)
    if (m_worker.joinable()) {
        m_worker.join();
    }

    m_running = true;

    m_worker = std::thread([this]() {
        int currentClicks = 0;

        while (m_running) {
            if (m_action) {
                m_action->execute();
            }

            if (!m_isInfinite) {
                currentClicks++;
                if (currentClicks >= m_repeatTimes) {
                    m_running = false; 
                    if (m_autoStopCallback) {
                        m_autoStopCallback();
                    }
                    break; 
                }
            }

            // Agora o compilador vai achar o wait() porque ele está na IStrategy!
            if (m_strategy && m_running) {
                m_strategy->wait(); 
            }
        }
    });
}

void Engine::stop() {
    m_running = false;
    if (m_worker.joinable()) {
        m_worker.join();
    }
}

bool Engine::isRunning() const {
    return m_running.load();
}