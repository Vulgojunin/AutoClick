#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <string>
#include <vector>
#include "../../external/nlohmann/json.hpp"

using json = nlohmann::json;

// Estrutura que guarda as configurações de clique
struct ClickConfig {
    int delay = 100;
    int mouseButton = 0; // 0: Esquerdo, 1: Direito
};

// Estrutura do Perfil completo
struct Profile {
    std::string name;
    ClickConfig config;
};

// Funções para o JSON entender nossas estruturas (ADL)
void to_json(json& j, const ClickConfig& c);
void from_json(const json& j, ClickConfig& c);
void to_json(json& j, const Profile& p);
void from_json(const json& j, Profile& p);

class ProfileManager {
public:
    ProfileManager(const std::string& directory = "profiles");
    
    bool salvar(const Profile& profile) const;
    bool carregar(const std::string& nome, Profile& profile) const;
    std::vector<std::string> listarPerfis() const;
    bool deletar(const std::string& nome) const;

private:
    void ensureDirectoryExists() const;
    std::string profilesDirectory;
};

#endif