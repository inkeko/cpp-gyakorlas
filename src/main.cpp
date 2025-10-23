#include "Parosito.h"
#include <iostream>
#include "Rendezo.h"
#include "FileIro.h"
#include "FileOlvaso.h" 

int main() {

    Parosito p;
p.hozzaad("Anna", 85);
p.hozzaad("Zoltán", 92);
p.hozzaad("Béla", 78);
p.hozzaad("Erika", 90);

Rendezo r;
FileIro f;

// Másolatot készítünk az eredményekről
auto lista = p.getEredmenyek();

r.rendezNevSzerint(lista);
r.szuresMinimumPonttal(lista, 80);
f.mentesFajlba(lista, "szurt_abc.txt");

#include "FileOlvaso.h"

// ...

FileOlvaso fo;
auto beolvasottLista = fo.beolvasFajlbol("szurt_abc.txt");

std::cout << "\nBeolvasott lista fájlból:\n";
for (const auto& p : beolvasottLista)
    std::cout << p.first << ": " << p.second << "\n";
}
