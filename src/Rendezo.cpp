#include "Rendezo.h"
#include <algorithm>

void Rendezo::rendezNevSzerint(std::vector<std::pair<std::string, int>>& lista) {
    std::sort(lista.begin(), lista.end(),
        [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
}

void Rendezo::rendezPontSzerint(std::vector<std::pair<std::string, int>>& lista) {
    std::sort(lista.begin(), lista.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
}

void Rendezo::szuresMinimumPonttal(std::vector<std::pair<std::string, int>>& lista, int minimumPont) {
    lista.erase(
        std::remove_if(lista.begin(), lista.end(),
            [minimumPont](const auto& p) {
                return p.second < minimumPont;
            }),
        lista.end()
    );
}