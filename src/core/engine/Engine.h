#ifndef ENGINE_H
#define ENGINE_H

#include <atomic>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <memory>
#include "core/interfaces/IStrategy.h"
#include "core/interfaces/IAction.h"

class Engine {
private:
    // Controle de estado atômico (evita condições de corrida)
    std::atomic<bool> m_running{false};
    
    // Componentes injetados via UseCases (Polimorfismo)
    std::unique_ptr<IStrategy> m_strategy;
    std::unique_ptr<IAction> m_action;
    
    // Sincronização para pausas precisas e interrupção imediata
    std::condition_variable m_cv;
    std::mutex m_mutex;
    std::thread m_worker;

    // O loop que roda na thread separada
    void workerLoop();

public:
    Engine() = default;
    
    // Destrutor garante que a thread seja encerrada corretamente ao fechar o app
    ~Engine();

    // Injeção de dependência com transferência de posse (std::move)
    void setStrategy(std::unique_ptr<IStrategy> strategy);
    void setAction(std::unique_ptr<IAction> action);
    
    void start();
    void stop();
    
    bool isRunning() const { return m_running.load(); }
};

#endif // ENGINE_H