#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include <memory>
#include "Engine.h"
#include "interfaces/IControllerObserver.h"

class Controller {
public:
    Controller();
    ~Controller();

    void registerObserver(IControllerObserver* observer);
    void notifyStatus(Status s);
    void requestStart();
    void requestStop();
    void updateDelay(int ms);

private:
    std::unique_ptr<Engine> m_engine; 
    std::vector<IControllerObserver*> m_observers;
};

#endif