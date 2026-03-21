#ifndef APPTYPES_H
#define APPTYPES_H

#include <string>

// Enums FORTES para evitar erros de digitação (strings)
enum class StrategyType {
    Fixed,
    Jitter
};

enum class ActionType {
    LeftClick,
    RightClick,
    MiddleClick
};

// Estrutura de Dados (DTO) que transporta as escolhas da UI para o Core
struct CommandData {
    int intervalMs = 1000;
    int jitterMs = 0;
    StrategyType strategy = StrategyType::Fixed;
    ActionType action = ActionType::LeftClick;
};

#endif // APPTYPES_H