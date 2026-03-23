#ifndef ENGINE_H
#define ENGINE_H

#include <thread>
#include <atomic>
#include <memory>
#include <functional>
#include "core/interfaces/IAction.h"
#include "core/interfaces/IStrategy.h"

class Engine {
public:
    Engine();
    ~Engine();

    void setAction(std::unique_ptr<IAction> action);
    void setStrategy(std::unique_ptr<IStrategy> strategy);
    
    // Configura o limite de cliques
    void setRepeatConfig(bool isInfinite, int repeatTimes);
    
    // Função para avisar a UI quando parar sozinho
    void setAutoStopCallback(std::function<void()> callback);

    void start();
    void stop();

    // NOVO: Retorna o status do motor. 
    // Essencial para travar o carregamento de perfis enquanto o clicker estiver atirando.
    bool isRunning() const;

private:
    std::atomic<bool> m_running;
    std::thread m_worker;
    
    std::unique_ptr<IAction> m_action;
    std::unique_ptr<IStrategy> m_strategy;

    // Variáveis de repetição
    bool m_isInfinite;
    int m_repeatTimes;
    std::function<void()> m_autoStopCallback;
};

#endif // ENGINE_H