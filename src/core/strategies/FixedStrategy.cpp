#include "FixedStrategy.h"

FixedStrategy::FixedStrategy(int ms) : m_interval(ms) {}

std::chrono::milliseconds FixedStrategy::getNextDelay() {
    return m_interval;
}

void FixedStrategy::reset() {
    // Sem estado para resetar em estratégia fixa
}