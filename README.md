# ParositasProjekt

C++ gyakorló projekt, amely nevekhez pontszámokat párosít, majd különböző módokon feldolgozza az adatokat. A cél a C++ STL, osztályok, fájlkezelés és moduláris programozás elsajátítása.

## 🔧 Funkciók

- Nevek és pontszámok tárolása (`std::pair`, `std::vector`)
- ABC sorrend szerinti rendezés
- Pontszám szerinti rendezés (csökkenő sorrend)
- Minimum pontszám szerinti szűrés
- Eredmények mentése fájlba
- Eredmények beolvasása fájlból

## 🧱 Fájlszerkezet

ParositasProjekt/ 
 ├── LICENSE.txt    
     ├── README.md 
├── src/             
 # Forrásfájlok │   
 ├── main.cpp │  
  ├── Parosito.cpp │  
   ├── Rendezo.cpp │   
   ├── FileIro.cpp │  
    ├── FileOlvaso.cpp ├── 
 include/         
  # Fejlécek │  
   ├── Parosito.h │  
    ├── Rendezo.h │  
     ├── FileIro.h │   
     ├── FileOlvaso.h 
    


## 🚀 Fordítás és futtatás

Ha saját gépen szeretnéd kipróbálni:

```bash
g++ src/main.cpp -o parositas
./parositas


Használhatsz saját -t VS Code-ban, vagy beállíthatod CMake/Makefile segítségével.

📜 Licenc
Ez a projekt szabadon felhasználható, módosítható és terjeszthető nem kereskedelmi célokra, különösen oktatási és tanulási célból.
Részletek: LICENSE.txt



👤 Szerző
Fejlesztő: Csaba (inkeko)
GitHub:github.com/inkeko

