#ifndef PAROSITO_H
#define PAROSITO_H

#include <string>
#include <vector>
#include <utility>

class Parosito {
private:
    std::vector<std::pair<std::string, int>> eredmenyek;

public:
    void hozzaad(const std::string& nev, int pont);
    const std::vector<std::pair<std::string, int>>& getEredmenyek() const;
};

#endif
