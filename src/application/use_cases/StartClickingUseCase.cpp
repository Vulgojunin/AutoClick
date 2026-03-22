#include "StartClickingUseCase.h"
#include "core/registry/ActionRegistry.h"
#include "core/registry/StrategyRegistry.h"
#include <QDebug>

// =================================================================
// ESSA É A LINHA QUE FALTAVA (O Construtor)
StartClickingUseCase::StartClickingUseCase(Engine* engine) : m_engine(engine) {}
// =================================================================

void StartClickingUseCase::execute(const CommandData& data) {
    // 1. Garantia de estado limpo (Thread safety)
    m_engine->stop();

    // 2. Tradução de tipos (String para Enum)
    ActionType aType = toActionType(data.actionName);
    StrategyType sType = toStrategyType(data.strategyName);

    // 3. Criação via Registries
    auto action = ActionRegistry::create(aType);
    auto strategy = StrategyRegistry::create(sType, data.intervalMs, data.jitterMs);

    // 4. Validação com Log de Erro (Garante que a Engine não quebre)
    if (!action || !strategy) {
        qDebug() << "[UseCase] Erro critico: Falha ao criar dependencias." 
                 << "Action:" << (action ? "OK" : "NULL")
                 << "Strategy:" << (strategy ? "OK" : "NULL")
                 << "| Inputs:" << QString::fromStdString(data.actionName) 
                 << QString::fromStdString(data.strategyName);
        return; 
    }

    // 5. Injeção e Partida
    m_engine->setAction(std::move(action));
    m_engine->setStrategy(std::move(strategy));
    
    qDebug() << "[UseCase] Engine configurada. Iniciando cliques...";
    m_engine->start();
}