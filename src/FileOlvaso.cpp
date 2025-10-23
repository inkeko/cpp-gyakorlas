#include "FileOlvaso.h"
#include <fstream>
#include <sstream>

std::vector<std::pair<std::string, int>> FileOlvaso::beolvasFajlbol(const std::string& fajlnev) {
    std::vector<std::pair<std::string, int>> lista;
    std::ifstream fajl(fajlnev);
    if (!fajl.is_open()) return lista;

    std::string sor;
    while (std::getline(fajl, sor)) {
        std::istringstream iss(sor);
        std::string nev;
        int pont;

        if (std::getline(iss, nev, ':') && iss >> pont) {
            // Tisztítás: szóközök eltávolítása
            nev.erase(nev.find_last_not_of(" \t")+1);
            lista.emplace_back(nev, pont);
        }
    }

    fajl.close();
    return lista;
}