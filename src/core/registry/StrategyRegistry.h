#ifndef STRATEGYREGISTRY_H
#define STRATEGYREGISTRY_H

#include <memory>
#include "core/interfaces/IStrategy.h"
#include "core/strategies/FixedStrategy.h"
#include "core/strategies/JitterStrategy.h"
#include "core/CoreTypes.h"

class StrategyRegistry {
public:
    // Factory Method: Decide qual estratégia instanciar com base na escolha do usuário
    static std::unique_ptr<IStrategy> create(StrategyType type, int intervalMs, int jitterMs) {
        switch (type) {
            case StrategyType::Fixed:  
                // Estratégia Fixa: precisa apenas do intervalo base
                return std::make_unique<FixedStrategy>(intervalMs);
                
            case StrategyType::Jitter: 
                // Estratégia Jitter (Aleatória): precisa do intervalo e da variação máxima
                return std::make_unique<JitterStrategy>(intervalMs, jitterMs);
                
            case StrategyType::None:
            default:                   
                // Proteção contra falhas: retorna nulo se o tipo for inválido ou não mapeado
                return nullptr;
        }
    }
};

#endif // STRATEGYREGISTRY_H