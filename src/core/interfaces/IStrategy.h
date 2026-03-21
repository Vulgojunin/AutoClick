#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include <chrono>

class IStrategy {
public:
    // Destrutor virtual é OBRIGATÓRIO em interfaces para evitar vazamento de memória
    virtual ~IStrategy() = default;

    // Retorna o tempo de espera para a próxima iteração
    virtual std::chrono::milliseconds getNextDelay() = 0;

    // Reinicia o estado da estratégia (útil para sequências complexas)
    virtual void reset() = 0;
};

#endif // ISTRATEGY_H