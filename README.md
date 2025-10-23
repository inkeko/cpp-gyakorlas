ParositasProjekt – C++ gyakorló alkalmazás

Leírás:
Ez a projekt egy C++ nyelvű gyakorló alkalmazás, amely nevekhez pontszámokat párosít, majd különböző módokon feldolgozza az adatokat. A cél a C++ STL, osztályok, fájlkezelés és moduláris programozás elsajátítása.

Funkciók:
- Nevek és pontszámok tárolása (std::pair és std::vector)
- ABC sorrend szerinti rendezés
- Pontszám szerinti rendezés (csökkenő sorrendben)
- Minimum pontszám szerinti szűrés
- Eredmények mentése fájlba
- Eredmények beolvasása fájlból

Fájlszerkezet:
├── src/
│   ├── main.cpp              – belépési pont, vezérlés
│   ├── Parosito.cpp          – adatkezelő osztály
│   ├── Rendezo.cpp           – szortírozási és szűrési logika
│   ├── FileIro.cpp           – fájlba írás
│   ├── FileOlvaso.cpp        – fájlból beolvasás
├── include/
│   ├── Parosito.h
│   ├── Rendezo.h
│   ├── FileIro.h
│   ├── FileOlvaso.h
└── README.txt                – projektleírás

Osztályok és szerepük:

1. Parosito
   - Feladata: az eredmények tárolása
   - Metódusok:
     - `hozzaad(nev, pont)` – új páros hozzáadása
     - `getEredmenyek()` – az aktuális lista lekérése
   - Ez az osztály az adatgazda, minden feldolgozás innen indul

2. Rendezo
   - Feladata: a lista feldolgozása
   - Metódusok:
     - `rendezNevSzerint(lista)` – név szerinti ABC sorrend
     - `rendezPontSzerint(lista)` – pontszám szerinti csökkenő sorrend
     - `szuresMinimumPonttal(lista, minimum)` – kiszűri az alacsony pontszámokat
   - Nem tárol adatot, csak feldolgoz

3. FileIro
   - Feladata: fájlba mentés
   - Metódus:
     - `mentesFajlba(lista, fajlnev)` – kiírja a listát egy `.txt` fájlba
   - Nem tárol adatot, csak kiírja

4. FileOlvaso
   - Feladata: fájlból beolvasás
   - Metódus:
     - `beolvasFajlbol(fajlnev)` – beolvassa a fájl tartalmát, és visszaadja párosított listaként
   - Nem tárol adatot, csak visszaadja

Használat:
1. A `main.cpp` példányosítja a `Parosito` osztályt, és hozzáad néhány nevet és pontszámot
2. A `getEredmenyek()` metódussal lekéri az adatokat
3. A `Rendezo` osztály feldolgozza a listát (rendezés, szűrés)
4. A `FileIro` osztály fájlba menti az eredményt
5. A `FileOlvaso` osztály képes visszaolvasni a fájl tartalmát újra feldolgozásra

Fejlesztői megjegyzés:
- A `main.cpp` nem tartalmaz logikát, csak vezérli a működést
- Az osztályok jól elkülönülnek: adatkezelés, feldolgozás, fájlkezelés
- A projekt könnyen bővíthető új funkciókkal (pl. statisztika, interaktív input)

Licenc:
Szabadon felhasználható tanulási célokra.

🧱 Parosito osztály – az adatgazda
🎯 Feladata:
- Tárolja az eredményeket: std::vector<std::pair<std::string, int>>
- Lehetővé teszi új párosok hozzáadását
- Visszaadja az aktuális listát más osztályoknak feldolgozásra
📄 Fejléc (Parosito.h)
class Parosito {
private:
    std::vector<std::pair<std::string, int>> eredmenyek;

public:
    void hozzaad(const std::string& nev, int pont);
    const std::vector<std::pair<std::string, int>>& getEredmenyek() const;
};


🔍 Részletes magyarázat:
- eredmenyek: privát vektor, ami neveket és pontszámokat tárol
- hozzaad(...): új párost ad hozzá a vektorhoz
- getEredmenyek(): visszaadja a vektort referenciaként, hogy ne másoljuk feleslegesen
📄 Megvalósítás (Parosito.cpp)
void Parosito::hozzaad(const std::string& nev, int pont) {
    eredmenyek.emplace_back(nev, pont);
}

const std::vector<std::pair<std::string, int>>& Parosito::getEredmenyek() const {
    return eredmenyek;
}


✅ Miért jó ez így?
- Az adatkezelés egy helyen történik
- A main.cpp nem manipulálja közvetlenül az adatokat
- A többi osztály (pl. Rendezo, FileIro) csak feldolgozza vagy kiírja az adatokat

🔄 Rendezo osztály – feldolgozás
🎯 Feladata:
- Rendezés név szerint (ABC)
- Rendezés pontszám szerint (csökkenő)
- Szűrés minimum pontszám alapján
📄 Fejléc (Rendezo.h)
class Rendezo {
public:
    void rendezNevSzerint(std::vector<std::pair<std::string, int>>& lista);
    void rendezPontSzerint(std::vector<std::pair<std::string, int>>& lista);
    void szuresMinimumPonttal(std::vector<std::pair<std::string, int>>& lista, int minimumPont);
};


🔍 Részletes magyarázat:
- Minden metódus referenciát kap, így nem másoljuk a listát
- A std::sort és std::remove_if algoritmusokat használjuk
- A lista paramétert helyben módosítjuk
📄 Megvalósítás (Rendezo.cpp)
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


✅ Miért jó ez így?
- A Rendezo osztály nem tárol adatot, csak feldolgoz
- A logika elkülönül az adattárolástól
- Könnyen bővíthető új metódusokkal (pl. növekvő sorrend, név szűrés)

🔗 Kapcsolat a main.cpp-ben
Parosito p;
p.hozzaad("Anna", 85);
// ...

auto lista = p.getEredmenyek(); // lekérjük az adatokat

Rendezo r;
r.rendezNevSzerint(lista);
r.szuresMinimumPonttal(lista, 80);


➡️ A main.cpp csak vezérli a működést, nem tartalmaz logikát.




