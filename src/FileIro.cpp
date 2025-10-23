#include "FileIro.h"
#include <fstream>

void FileIro::mentesFajlba(const std::vector<std::pair<std::string, int>>& lista, const std::string& fajlnev) {
    std::ofstream fajl(fajlnev);
    if (!fajl.is_open()) return;

    for (const auto& p : lista) {
        fajl << p.first << ": " << p.second << "\n";
    }

    fajl.close();
}