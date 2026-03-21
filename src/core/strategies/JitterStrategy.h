#ifndef JITTERSTRATEGY_H
#define JITTERSTRATEGY_H

#include "core/interfaces/IStrategy.h"
#include <chrono>
#include <random>

class JitterStrategy : public IStrategy {
private:
    std::chrono::milliseconds m_baseInterval;
    int m_maxJitterMs;
    
    // Gerador de números aleatórios moderno do C++
    std::mt19937 m_rng;

public:
    JitterStrategy(int baseMs, int jitterMs) 
        : m_baseInterval(baseMs), m_maxJitterMs(jitterMs) 
    {
        // Inicializa o gerador com uma semente baseada no tempo real
        std::random_device rd;
        m_rng.seed(rd());
    }

    std::chrono::milliseconds getNextDelay() override {
        if (m_maxJitterMs <= 0) return m_baseInterval;

        // Cria uma distribuição entre -jitter e +jitter
        std::uniform_int_distribution<int> dist(-m_maxJitterMs, m_maxJitterMs);
        int variation = dist(m_rng);

        return m_baseInterval + std::chrono::milliseconds(variation);
    }

    void reset() override {
        // Reinicia a semente se necessário (opcional)
    }
};

#endif // JITTERSTRATEGY_H