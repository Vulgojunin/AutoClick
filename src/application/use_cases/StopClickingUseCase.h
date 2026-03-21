#ifndef STOPCLICKINGUSECASE_H
#define STOPCLICKINGUSECASE_H

#include "core/engine/Engine.h"

class StopClickingUseCase {
private:
    Engine* m_engine;

public:
    explicit StopClickingUseCase(Engine* engine);
    void execute();
};

#endif // STOPCLICKINGUSECASE_H