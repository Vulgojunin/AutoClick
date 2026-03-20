#include "ProfileManager.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

// Implementação das funções de conversão JSON
void to_json(json& j, const ClickConfig& c) {
    j = json{{"delay", c.delay}, {"mouseButton", c.mouseButton}};
}

void from_json(const json& j, ClickConfig& c) {
    j.at("delay").get_to(c.delay);
    j.at("mouseButton").get_to(c.mouseButton);
}

void to_json(json& j, const Profile& p) {
    j = json{{"name", p.name}, {"config", p.config}};
}

void from_json(const json& j, Profile& p) {
    j.at("name").get_to(p.name);
    j.at("config").get_to(p.config);
}

// Implementação do Manager
ProfileManager::ProfileManager(const std::string& dir) : profilesDirectory(dir) {
    ensureDirectoryExists();
}

void ProfileManager::ensureDirectoryExists() const {
    if (!fs::exists(profilesDirectory)) {
        fs::create_directory(profilesDirectory);
    }
}

bool ProfileManager::salvar(const Profile& profile) const {
    try {
        std::string filePath = profilesDirectory + "/" + profile.name + ".json";
        std::ofstream file(filePath);
        if (file.is_open()) {
            json j = profile;
            file << j.dump(4);
            return true;
        }
    } catch (...) {}
    return false;
}

bool ProfileManager::carregar(const std::string& nome, Profile& profile) const {
    try {
        std::string filePath = profilesDirectory + "/" + nome + ".json";
        std::ifstream file(filePath);
        if (file.is_open()) {
            json j;
            file >> j;
            profile = j.get<Profile>();
            return true;
        }
    } catch (...) {}
    return false;
}

std::vector<std::string> ProfileManager::listarPerfis() const {
    std::vector<std::string> lista;
    for (const auto& entry : fs::directory_iterator(profilesDirectory)) {
        if (entry.path().extension() == ".json") {
            lista.push_back(entry.path().stem().string());
        }
    }
    return lista;
}

bool ProfileManager::deletar(const std::string& nome) const {
    std::string filePath = profilesDirectory + "/" + nome + ".json";
    return fs::remove(filePath);
}