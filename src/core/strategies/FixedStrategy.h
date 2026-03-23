#ifndef FIXEDSTRATEGY_H
#define FIXEDSTRATEGY_H

#include "core/interfaces/IStrategy.h"
#include <thread>
#include <chrono>

class FixedStrategy : public IStrategy {
public:
    explicit FixedStrategy(int intervalMs) : m_intervalMs(intervalMs) {}

    // Implementa o wait esperando o tempo fixo
    void wait() override {
        if (m_intervalMs > 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(m_intervalMs));
        }
    }

private:
    int m_intervalMs;
};

#endif // FIXEDSTRATEGY_H