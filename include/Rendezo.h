#ifndef RENDEZO_H
#define RENDEZO_H

#include <vector>
#include <string>
#include <utility>

class Rendezo {
public:
    void rendezNevSzerint(std::vector<std::pair<std::string, int>>& lista);
    void rendezPontSzerint(std::vector<std::pair<std::string, int>>& lista);
    void szuresMinimumPonttal(std::vector<std::pair<std::string, int>>& lista, int minimumPont);
};

#endif