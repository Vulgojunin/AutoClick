#include "ProfileManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
namespace fs = std::filesystem; 

// --- Serialização ---
void to_json(json& j, const ClickConfig& c) {
    j = json{{"intervalMs", c.intervalMs}, {"clickType", c.clickType}};
}

void from_json(const json& j, ClickConfig& c) {
    j.at("intervalMs").get_to(c.intervalMs);
    j.at("clickType").get_to(c.clickType);
}

void to_json(json& j, const Profile& p) {
    j = json{{"name", p.name}, {"clickConfig", p.clickConfig}};
}

void from_json(const json& j, Profile& p) {
    j.at("name").get_to(p.name);
    j.at("clickConfig").get_to(p.clickConfig);
}
// --------------------

ProfileManager::ProfileManager(const std::string& dir) : profilesDirectory(dir) {
    ensureDirectoryExists();
}

void ProfileManager::ensureDirectoryExists() const {
    if (!fs::exists(profilesDirectory)) {
        if (fs::create_directory(profilesDirectory)) {
            std::cout << "[ProfileManager] Pasta criada com sucesso: " << profilesDirectory << std::endl;
        } else {
            std::cout << "[ProfileManager] ERRO GRAVE: O Windows bloqueou a criacao da pasta!" << std::endl;
        }
    }
}

bool ProfileManager::salvar(const Profile& profile) const {
    try {
        ensureDirectoryExists();
        std::string filePath = profilesDirectory + "/" + profile.name + ".json";
        
        std::cout << "[ProfileManager] Tentando salvar em: " << fs::absolute(filePath).string() << std::endl;
        
        json j = profile; 
        std::ofstream file(filePath);
        if (!file.is_open()) {
            std::cout << "[ProfileManager] ERRO: Nao foi possivel criar o arquivo .json!" << std::endl;
            return false;
        }
        
        file << j.dump(4); 
        std::cout << "[ProfileManager] SUCESSO! Perfil salvo." << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "[ProfileManager] Excecao ao salvar: " << e.what() << '\n';
        return false;
    }
}

bool ProfileManager::carregar(const std::string& nome, Profile& profile) const {
    try {
        std::string filePath = profilesDirectory + "/" + nome + ".json";
        std::cout << "[ProfileManager] Tentando carregar de: " << fs::absolute(filePath).string() << std::endl;
        
        if (!fs::exists(filePath)) {
            std::cout << "[ProfileManager] ERRO: Arquivo nao existe!" << std::endl;
            return false;
        }

        std::ifstream file(filePath);
        if (!file.is_open()) return false;

        json j;
        file >> j;
        profile = j.get<Profile>(); 
        
        std::cout << "[ProfileManager] SUCESSO! Perfil carregado." << std::endl;
        return true;
    } catch (const std::exception& e) {
        std::cerr << "[ProfileManager] Excecao ao carregar: " << e.what() << '\n';
        return false;
    }
}

std::vector<std::string> ProfileManager::listarPerfis() const {
    std::vector<std::string> nomes;
    try {
        ensureDirectoryExists();
        for (const auto& entry : fs::directory_iterator(profilesDirectory)) {
            if (entry.path().extension() == ".json") {
                nomes.push_back(entry.path().stem().string()); 
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "[ProfileManager] Erro ao listar: " << e.what() << '\n';
    }
    return nomes;
}

bool ProfileManager::deletar(const std::string& nome) const {
    try {
        std::string filePath = profilesDirectory + "/" + nome + ".json";
        if (fs::exists(filePath)) {
            fs::remove(filePath);
            std::cout << "[ProfileManager] SUCESSO! Perfil apagado: " << nome << std::endl;
            return true;
        }
        return false;
    } catch (const std::exception& e) {
        std::cerr << "[ProfileManager] Erro ao deletar: " << e.what() << '\n';
        return false;
    }
}