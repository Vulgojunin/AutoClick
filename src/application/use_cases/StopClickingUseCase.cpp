#include "application/use_cases/StopClickingUseCase.h"

StopClickingUseCase::StopClickingUseCase(Engine* engine) : m_engine(engine) {}

void StopClickingUseCase::execute() {
    // Apenas garantimos que o ponteiro é válido. 
    // A própria Engine sabe lidar com o stop com segurança.
    if (m_engine) {
        m_engine->stop();
    }
}