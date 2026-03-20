#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include <string>
#include "Registry.h"
#include "Engine.h"
#include "interfaces/IControllerObserver.h"

class Controller {
public:
    Controller();
    ~Controller();

    // Gestão de Observadores (UI)
    void registerObserver(IControllerObserver* observer);
    void notifyStatus(Status s);

    // Controle de Execução
    void requestStart();
    void requestStop();
    void toggleExecution(); // Atalho F6
    void updateDelay(int ms);

    // Interface com o Registry (Para a UI Imutável)
    std::vector<std::string> getAvailableActions() const;
    std::vector<std::string> getAvailableStrategies() const;
    
    void selectAction(const std::string& name);
    void selectStrategy(const std::string& name);

private:
    std::unique_ptr<Engine> m_engine;
    Registry m_registry;
    
    std::vector<IControllerObserver*> m_observers;
    
    IAction* m_currentAction = nullptr;
    IStrategy* m_currentStrategy = nullptr;
    
    bool m_isRunning = false;
};

#endif