#include "my.h"

void rasoZodziuSkaiciu( map<wstring, int>& zodziuSkaicius, wstring filename){
    //wofstream fr;
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    //fr.imbue(locale(fr.getloc(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 1 file for writing.\n";
    return;
}
    for (const auto& [zodziai, skaicius] : zodziuSkaicius){
        if (skaicius > 1){
            fr << left << setw(20) << zodziai << ": " << left << skaicius << "\n";
        }
    }
    fr.close();
}
//--------------------------------------------------------------------
void CrossReference(map<wstring, set<int>>& zodziuEiles, map<wstring, int>& zodziuSkaicius, wstring filename){
    //wofstream fr;
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    //fr.imbue(locale(fr.getloc(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 2 file for writing.\n";
    return;
}

    for (const auto& [zodziai, eiles] : zodziuEiles){
        if (zodziuSkaicius.at(zodziai) > 1){
            fr << left << setw(20) << zodziai << ": ";
            for (int eile : eiles){
                fr << left << eile << " ";
            }
            fr << "\n";
        }
    }
fr.close();
}
//--------------------------------------------------------------------
void rasoURL(set<wstring>& urls, wstring filename){
    //wofstream fr;
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    //fr.imbue(locale(fr.getloc(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 3 file for writing.\n";
    return;
}

    for (const auto& url : urls){
        fr << url << "\n";
    }
    fr.close();
}
//--------------------------------------------------------------------
wstring istrintiZodi(wstring& zodis){

     wstring istrintas;
     for (wchar_t zd : zodis) {
         if (iswalpha(zd) || iswdigit(zd)) {
             istrintas += towlower(zd);
         }
     }
    return istrintas;
}
//--------------------------------------------------------------------
bool yraURL(const wstring& zodis) {
     return zodis.find(L"http://") != std::wstring::npos ||
            zodis.find(L"https://") != std::wstring::npos ||
            zodis.find(L"www.") != std::wstring::npos;
    //return false;
}

//--------------------------------------------------------------------
void failoSkaitymas(map<wstring, int>& zodziuSkaicius,
                    map<wstring, set<int>>& zodziuEiles,
                    set<wstring>& urls) {

    wstring eile;
    int eilesNr = 1;
    //cout << "Opening file..." << endl;

    wifstream fd ("tekstas.txt");
    fd.imbue(locale(fd.getloc(), new codecvt_utf8<wchar_t>));


    if (!fd.is_open())
    {
        wcerr << L"Nepavyko atidaryti failo\n";
        //system("pause");
        //exit(1);
        //return;
    }

    //cout << "File opened successfully." << endl;
    while (getline(fd, eile))
    {
        //cout << "Reading line: " << eile << endl;  
        wstringstream ss(eile);
        wstring zodis;
        while (ss>>zodis){
             //cout << "Found word: " << zodis << endl;

            if (yraURL(zodis)){
                 // cout << "It's a URL." << endl;
                urls.insert(zodis);
        }else {
            wstring istrintas = istrintiZodi(zodis);
              //cout << "It's a word." << endl;
            if (!istrintas.empty()) {
                zodziuSkaicius[istrintas]++;
                zodziuEiles[istrintas].insert(eilesNr);
            }
        }
    }
    eilesNr++;
}
fd.close();
//cout << "File reading finished." << endl;
}
//--------------------------------------------------------------------
int main() {
    SetConsoleOutputCP(CP_UTF8);
    //  std::locale::global(std::locale("en_US.UTF-8"));
    //std::cout << "Program started.\n";
    //system("pause");
    //SetConsoleOutputCP(CP_UTF8);
    map<wstring, int> zodziuSkaicius;
    map<wstring, set<int>> zodziuEiles;
    set<wstring> urls;

    failoSkaitymas(zodziuSkaicius, zodziuEiles, urls);
    rasoZodziuSkaiciu(zodziuSkaicius, L"Zodziu_skaicius.txt");
    CrossReference(zodziuEiles,zodziuSkaicius, L"Cross_reference.txt");
    rasoURL(urls, L"URLs.txt");

    system("pause");
    return 0;
}
