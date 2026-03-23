#include "application/use_cases/StartClickingUseCase.h"
#include "core/registry/ActionRegistry.h"
#include "core/registry/StrategyRegistry.h"
#include "core/CoreTypes.h"

StartClickingUseCase::StartClickingUseCase(Engine* engine) : m_engine(engine) {}

void StartClickingUseCase::execute(const CommandData& data) {
    ActionType actType = ActionType::LeftClick;
    if (data.actionName == "rightclick") actType = ActionType::RightClick;

    auto action = ActionRegistry::create(actType);
    
    StrategyType stratType = (data.strategyName == "jitter") ? StrategyType::Jitter : StrategyType::Fixed;
    auto strategy = StrategyRegistry::create(stratType, data.intervalMs, data.jitterMs);

    m_engine->setAction(std::move(action));
    m_engine->setStrategy(std::move(strategy));
    
    // Injeta a configuração de repetição lida do UseCase
    m_engine->setRepeatConfig(data.isInfinite, data.repeatTimes);

    m_engine->start();
}