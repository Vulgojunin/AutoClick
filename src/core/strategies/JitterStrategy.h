#ifndef JITTERSTRATEGY_H
#define JITTERSTRATEGY_H

#include "core/interfaces/IStrategy.h"
#include <thread>
#include <chrono>
#include <random>

class JitterStrategy : public IStrategy {
public:
    JitterStrategy(int intervalMs, int jitterMs) 
        : m_intervalMs(intervalMs), m_jitterMs(jitterMs) {}

    // Implementa o wait com tempo aleatório (Jitter)
    void wait() override {
        std::default_random_engine generator(std::random_device{}());
        std::uniform_int_distribution<int> distribution(-m_jitterMs, m_jitterMs);
        
        int offset = distribution(generator);
        int finalWait = m_intervalMs + offset;

        if (finalWait < 1) finalWait = 1; // Proteção para não esperar tempo negativo
        
        std::this_thread::sleep_for(std::chrono::milliseconds(finalWait));
    }

private:
    int m_intervalMs;
    int m_jitterMs;
};

#endif // JITTERSTRATEGY_H