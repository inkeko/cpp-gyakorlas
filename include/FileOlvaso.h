#ifndef FILEOLVASO_H
#define FILEOLVASO_H

#include <vector>
#include <string>
#include <utility>

class FileOlvaso {
public:
    std::vector<std::pair<std::string, int>> beolvasFajlbol(const std::string& fajlnev);
};

#endif