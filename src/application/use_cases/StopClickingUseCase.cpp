#include "application/use_cases/StopClickingUseCase.h"

StopClickingUseCase::StopClickingUseCase(Engine* engine) : m_engine(engine) {}

void StopClickingUseCase::execute() {
    if (m_engine && m_engine->isRunning()) {
        m_engine->stop();
    }
}