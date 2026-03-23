#ifndef APPTYPES_H
#define APPTYPES_H

#include <string>

struct CommandData {
    int intervalMs = 100;
    int jitterMs = 0;
    std::string actionName = "leftclick";
    std::string strategyName = "fixed";
    
    // Novas variáveis para o modo Repeat!
    bool isInfinite = true;
    int repeatTimes = 0;
};

#endif // APPTYPES_H