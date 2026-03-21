#include "application/use_cases/StartClickingUseCase.h"
#include "core/registry/StrategyRegistry.h"
#include "core/registry/ActionRegistry.h"

StartClickingUseCase::StartClickingUseCase(Engine* engine) : m_engine(engine) {}

void StartClickingUseCase::execute(const CommandData& data) {
    if (!m_engine) return;

    auto strategy = StrategyRegistry::create(data.strategy, data.intervalMs, data.jitterMs);
    auto action = ActionRegistry::create(data.action);

    if (strategy && action) {
        m_engine->setStrategy(std::move(strategy));
        m_engine->setAction(std::move(action));
        m_engine->start();
    }
}