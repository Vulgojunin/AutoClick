#ifndef STRATEGYREGISTRY_H
#define STRATEGYREGISTRY_H

#include <memory>
#include "core/interfaces/IStrategy.h"
#include "core/strategies/FixedStrategy.h"
#include "core/strategies/JitterStrategy.h"
#include "core/CoreTypes.h"

class StrategyRegistry {
public:
    static std::unique_ptr<IStrategy> create(StrategyType type, int interval, int jitter) {
        switch (type) {
            case StrategyType::Fixed:  
                return std::make_unique<FixedStrategy>(interval);
            case StrategyType::Jitter: 
                return std::make_unique<JitterStrategy>(interval, jitter);
            case StrategyType::None:
            default:                   
                return nullptr;
        }
    }
};

#endif // STRATEGYREGISTRY_H