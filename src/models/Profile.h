#pragma once
#include <string>

// Estrutura que guarda a configuração atual do motor
struct ClickConfig {
    int intervalMs = 100;
    int clickType = 0; // 0 = Esquerdo, 1 = Direito, 2 = Meio
};

// O Perfil completo
struct Profile {
    std::string name;
    ClickConfig clickConfig;
};