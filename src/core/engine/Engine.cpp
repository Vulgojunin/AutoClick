#include "core/engine/Engine.h"
#include <chrono>

Engine::~Engine() {
    stop(); // Garante limpeza ao destruir o objeto
}

void Engine::setStrategy(std::unique_ptr<IStrategy> strategy) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_strategy = std::move(strategy);
}

void Engine::setAction(std::unique_ptr<IAction> action) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_action = std::move(action);
}

void Engine::start() {
    // Se já estiver rodando, não faz nada
    if (m_running.load()) return;

    m_running.store(true);
    
    // Se houver uma thread antiga finalizando, espera ela
    if (m_worker.joinable()) {
        m_worker.join();
    }

    // Lança a execução para uma thread de background
    m_worker = std::thread(&Engine::workerLoop, this);
}

void Engine::stop() {
    m_running.store(false);
    m_cv.notify_all(); // Acorda a thread do worker caso ela esteja "dormindo" no intervalo
    
    if (m_worker.joinable()) {
        m_worker.join();
    }
}

void Engine::workerLoop() {
    // Verificação de segurança: sem estratégia ou ação, não há o que fazer
    if (!m_strategy || !m_action) {
        m_running.store(false);
        return;
    }

    m_strategy->reset();

    while (m_running.load()) {
        // 1. Executa a ação (O Clique)
        m_action->execute();

        // 2. Calcula o próximo tempo de espera baseado na estratégia
        auto delay = m_strategy->getNextDelay();
        auto nextWakeup = std::chrono::steady_clock::now() + delay;

        // 3. Dorme de forma inteligente (interrompível)
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_cv.wait_until(lock, nextWakeup, [this] { return !m_running.load(); })) {
            // Se wait_until retornou verdadeiro, significa que m_running virou false (Stop clicado)
            break;
        }
    }
}