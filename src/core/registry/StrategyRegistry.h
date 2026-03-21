#ifndef STRATEGYREGISTRY_H
#define STRATEGYREGISTRY_H

#include <memory>
#include "core/interfaces/IStrategy.h"
#include "core/strategies/FixedStrategy.h"
#include "core/strategies/JitterStrategy.h"
#include "application/use_cases/AppTypes.h"

class StrategyRegistry {
public:
    // Cria a estratégia baseada no Enum tipado
    static std::unique_ptr<IStrategy> create(StrategyType type, int value, int jitter = 0) {
        switch (type) {
            case StrategyType::Fixed:
                return std::make_unique<FixedStrategy>(value);
            
            case StrategyType::Jitter:
                return std::make_unique<JitterStrategy>(value, jitter);
            
            default:
                return nullptr;
        }
    }
};

#endif // STRATEGYREGISTRY_H