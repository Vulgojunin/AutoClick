#include "JitterStrategy.h"

JitterStrategy::JitterStrategy(int baseMs, int jitterMs) 
    : m_baseInterval(baseMs), m_maxJitterMs(jitterMs) {
    std::random_device rd;
    m_rng.seed(rd());
}

std::chrono::milliseconds JitterStrategy::getNextDelay() {
    std::uniform_int_distribution<int> dist(-m_maxJitterMs, m_maxJitterMs);
    int offset = dist(m_rng);
    return m_baseInterval + std::chrono::milliseconds(offset);
}

void JitterStrategy::reset() {
    // Reinicia o seed se quiser um comportamento idêntico em cada Start
}