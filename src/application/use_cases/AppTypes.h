#ifndef APPTYPES_H
#define APPTYPES_H

#include <string>
#include <algorithm>
#include <cctype>
#include "core/CoreTypes.h" // Importa APENAS os tipos, não as interfaces

struct CommandData {
    int intervalMs;
    int jitterMs;
    std::string actionName;
    std::string strategyName;
};

// Normalização robusta com proteção para unsigned char
inline std::string normalize(std::string data) {
    std::transform(data.begin(), data.end(), data.begin(), 
        [](unsigned char c){ return std::tolower(c); });
    
    data.erase(std::remove_if(data.begin(), data.end(),
        [](unsigned char c){ return std::isspace(c); }), 
        data.end());
        
    return data;
}

inline ActionType toActionType(const std::string& name) {
    std::string n = normalize(name);
    if (n == "cliquedireito" || n == "rightclick") return ActionType::RightClick;
    if (n == "cliqueesquerdo" || n == "leftclick") return ActionType::LeftClick;
    return ActionType::None;
}

inline StrategyType toStrategyType(const std::string& name) {
    std::string n = normalize(name);
    if (n == "jitter") return StrategyType::Jitter;
    if (n == "fixed" || n == "fixo") return StrategyType::Fixed;
    return StrategyType::None; // Tipo correto retornado
}

#endif // APPTYPES_H