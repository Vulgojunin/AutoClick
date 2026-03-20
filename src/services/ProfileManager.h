#pragma once
#include <vector>
#include <string>
#include "../models/Profile.h"

class ProfileManager {
private:
    std::string profilesDirectory;
    void ensureDirectoryExists() const;

public:
    // Construtor define a pasta onde os ficheiros JSON vão ficar (ex: "profiles/")
    ProfileManager(const std::string& dir = "profiles");

    bool salvar(const Profile& profile) const;
    bool carregar(const std::string& nome, Profile& profile) const;
    bool deletar(const std::string& nome) const;
    // Devolve uma lista com os nomes de todos os perfis guardados
    std::vector<std::string> listarPerfis() const;
};