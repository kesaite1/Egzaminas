# Egzamino užduotis

## Teksto apdorojimo programa

**Aprašymas**

Ši programa perskaito teksto failą, jį apdoroja ir sukuria tris atskirus failus:
1. `Zodziu_skaicius.txt` - jame atspausdinami žodžiai, kurie pasikartoja daugiau nei vieną kartą bei parašomas jų pasikartojimų tekste skaičius;
2. `Cross_reference.txt` - šiame faile nurodomos eilutės, kuriose pasikartojo žodžiai;
3. `URLs.txt` - atspausdinami tekste rasti URL adresai.


**Diegimo ir paleidimo instrukcija**

1. Atsisiųskite šią repozitoriją į savo kompiuterį.
2. Paleiskite `zodziai.bat` failą - jis automatiškai sukurs `build` katalogą, kuriame bus sukurtas programos vykdomasis failas `zodziai.exe`.
3. Savo `.txt` failą, su norimu apdoroti tekstu, įkelkite į `zodziai.exe` failo direktoriją.
4. Paleiskite `zodziai.exe` failą, įveskite savo tekstinio failo pavadinimą (pvz. *tekstas.txt*).
5. Rezultatų failai bus sukurti ir išsaugoti `zodziai.exe` failo direktorijoje.


**Klaidų aptikimas**

Nepavykus atidaryti, neradus nurodyto failo, atsiras pranešimas: "Nepavyko atidaryti failo".
Nepavykus sukurti kažkurio is failų, atsiras pranešimas: "Nepavyko atidaryti "failo numeris" failo rasymui".


**Funkcijos kode**

- rasoZodziuSkaiciu;
- CrossReference;
- rasoURL;
- istrintiZodi;
- yraURL;
- failoSkaitymas;

**Projekto struktūra**

Svarbiausi failai, įeinantys į projektą:
- `zodziai.cpp` - main funkcija;
- `unctions.cpp` - funkcijų aprašymai (angl. *definitions*);
- ``functions.h`` - funkcijų deklaracijos (angl. *declarations*);
- `my.h` - įtrauktos bibliotekos ir using namespace santraukos;
- `CMakeLists.txt` - projekto kompiliavimo konfigūracija naudojant CMake;
- `zodziai.bat` - programos automatinis kompiliavimas, sukuriamas build folder su zodziai.exe vykdomuoju failu;


**Main funkcija**

<pre> 
int main() {
SetConsoleOutputCP(CP_UTF8);
map<wstring, int> zodziuSkaicius; 
map<wstring, set<int>> zodziuEiles; 
set<wstring> urls; 
failoSkaitymas(zodziuSkaicius, zodziuEiles, urls);     
rasoZodziuSkaiciu(zodziuSkaicius, L"Zodziu_skaicius.txt"); 
CrossReference(zodziuEiles,zodziuSkaicius, L"Cross_reference.txt"); 
rasoURL(urls, L"URLs.txt"); 
cout << "Programa ivykdyta. Failai sukurti.\n"; 
return 0; 
} </pre>


![image](https://github.com/user-attachments/assets/98b9425e-da1e-4b68-b33f-95c55f3fb8fa)
![image](https://github.com/user-attachments/assets/739e3e47-3bfa-489c-9d75-8f9a4b630bc4)
![image](https://github.com/user-attachments/assets/45d8098e-64d6-4eba-85eb-ddf32b865991)







