#ifndef STARTCLICKINGUSECASE_H
#define STARTCLICKINGUSECASE_H

#include "core/engine/Engine.h"
#include "application/use_cases/AppTypes.h"

class StartClickingUseCase {
private:
    Engine* m_engine;

public:
    // Recebe o endereço do motor que o Controller gerencia
    explicit StartClickingUseCase(Engine* engine);
    
    // Executa a lógica de montagem da estratégia e ação
    void execute(const CommandData& data);
};

#endif // STARTCLICKINGUSECASE_H