#ifndef EXECUTIONNOTIFIER_H
#define EXECUTIONNOTIFIER_H

#include <vector>
#include <mutex>
#include <algorithm>
#include "core/interfaces/IControllerObserver.h"

class ExecutionNotifier {
private:
    std::vector<IControllerObserver*> m_observers;
    std::mutex m_mutex;

public:
    void addObserver(IControllerObserver* obs) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (std::find(m_observers.begin(), m_observers.end(), obs) == m_observers.end()) {
            m_observers.push_back(obs);
        }
    }

    // CORREÇÃO: Remoção segura do Observer
    void removeObserver(IControllerObserver* obs) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_observers.erase(
            std::remove(m_observers.begin(), m_observers.end(), obs), 
            m_observers.end()
        );
    }

    void notifyStarted() {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto obs : m_observers) obs->onExecutionStarted();
    }

    void notifyStopped() {
        std::lock_guard<std::mutex> lock(m_mutex);
        for (auto obs : m_observers) obs->onExecutionStopped();
    }
};

#endif // EXECUTIONNOTIFIER_H