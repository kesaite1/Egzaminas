#include "my.h"
#include "functions.h"


void rasoZodziuSkaiciu( map<wstring, int>& zodziuSkaicius, wstring filename){
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 1 file for writing.\n";
    return;
}
fr << left << setw(22) << "Zodziai" << "Pasikartojimu skaicius\n";
fr << "----------------------------------------------------------\n";
    for (const auto& [zodziai, skaicius] : zodziuSkaicius){
        if (skaicius > 1){
            fr << left << setw(20) << zodziai << ": " << left << skaicius << "\n";
        }
    }
    fr.close();
}
//--------------------------------------------------------------------
void CrossReference(map<wstring, set<int>>& zodziuEiles, map<wstring, int>& zodziuSkaicius, wstring filename){
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 2 file for writing.\n";
    return;
}
fr << left << setw(22) << "Zodis" << "Eiluciu nr. \n";
fr << "-------------------------------------------------------------------\n";
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
    wofstream fr(filename.c_str());
    fr.imbue(locale(locale(), new codecvt_utf8<wchar_t>));
    if (!fr.is_open()) {
    cerr << "Failed to open 3 file for writing.\n";
    return;
}
    fr << "URL adresai: \n";
    fr << "-----------------------------------------------------------\n";
    for (const auto& url : urls){
        fr << url << "\n";
    }
    fr.close();
}
//--------------------------------------------------------------------
wstring istrintiZodi(wstring& zodis){

     wstring istrintas;
     for (wchar_t zd : zodis) {
         if (iswalpha(zd)) {

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
}

//--------------------------------------------------------------------
void failoSkaitymas(map<wstring, int>& zodziuSkaicius,
                    map<wstring, set<int>>& zodziuEiles,
                    set<wstring>& urls) {

    wstring eile;
    int eilesNr = 1;
    wifstream fd ("tekstas.txt");
    fd.imbue(locale(fd.getloc(), new codecvt_utf8<wchar_t>));

    if (!fd.is_open())
    {
        wcerr << L"Nepavyko atidaryti failo\n";
    }

    while (getline(fd, eile))
    {
        wstringstream ss(eile);
        wstring zodis;

        while (ss>>zodis){
            while (!zodis.empty() && iswpunct(zodis.front()))
            zodis.erase(0,1);
            while (!zodis.empty() && iswpunct(zodis.back()))
            zodis.pop_back();

            if (yraURL(zodis)){
                urls.insert(zodis);
        }else {
            wstring istrintas = istrintiZodi(zodis);
            if (!istrintas.empty()) {
                zodziuSkaicius[istrintas]++;
                zodziuEiles[istrintas].insert(eilesNr);
            }
        }
    }
    eilesNr++;
}
fd.close();
}