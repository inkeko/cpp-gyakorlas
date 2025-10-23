#include "Parosito.h"
#include <sstream>

void Parosito::hozzaad(const std::string& nev, int pont) {
    eredmenyek.emplace_back(nev, pont);
}

const std::vector<std::pair<std::string, int>>& Parosito::getEredmenyek() const {
    return eredmenyek;
}


