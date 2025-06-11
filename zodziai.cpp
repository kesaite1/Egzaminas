#include "my.h"
#include "functions.h"

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
    //system("pause");
    return 0;
}
