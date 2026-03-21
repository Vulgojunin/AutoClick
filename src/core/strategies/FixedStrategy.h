#ifndef FIXEDSTRATEGY_H
#define FIXEDSTRATEGY_H

#include "core/interfaces/IStrategy.h"
#include <chrono>

class FixedStrategy : public IStrategy {
private:
    std::chrono::milliseconds m_interval;

public:
    // Recebe o valor em milissegundos e converte para o tipo chrono
    explicit FixedStrategy(int ms) : m_interval(ms) {}

    std::chrono::milliseconds getNextDelay() override {
        return m_interval;
    }

    void reset() override {
        // Estratégia fixa não possui estado acumulado
    }
};

#endif // FIXEDSTRATEGY_H