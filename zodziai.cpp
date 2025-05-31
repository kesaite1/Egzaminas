#include "my.h"

void rasoZodziuSkaiciu( map<string, int>& zodziuSkaicius, string filename){
    ofstream fr (filename);

    for (const auto& [zodziai, skaicius] : zodziuSkaicius){
        if (skaicius > 1){
            fr << left << setw(10) << zodziai << ": " << left << skaicius << "\n";
        }
    }
    fr.close();
}
//--------------------------------------------------------------------
void CrossReference(map<string, set<int>>& zodziuEiles, map<string, int>& zodziuSkaicius, string filename){
    ofstream fr (filename);

    for (const auto& [zodziai, eiles] : zodziuEiles){
        if (zodziuSkaicius.at(zodziai) > 1){
            fr << left << setw(15) << zodziai << ": ";
            for (int eile : eiles){
                fr << left << eile << " ";
            }
            fr << "\n";
        }
    }
fr.close();
}
//--------------------------------------------------------------------
void rasoURL(set<string>& urls, string filename){
    ofstream fr (filename);

    for (const auto& url : urls){
        fr << url << "\n";
    }
    fr.close();
}
//--------------------------------------------------------------------
string istrintiZodi(string& zodis){

    string istrintas;
    for (char zd : zodis) {
        if (isalpha(zd) || isdigit(zd)) {
            istrintas += tolower(zd);
        }
    }
    return istrintas;
}
//--------------------------------------------------------------------
bool yraURL(const string& zodis) {
    return zodis.find("http://") != std::string::npos ||
           zodis.find("https://") != std::string::npos ||
           zodis.find("www.") != std::string::npos;
}

//--------------------------------------------------------------------
void failoSkaitymas(map<string, int>& zodziuSkaicius,
                    map<string, set<int>>& zodziuEiles,
                    set<string>& urls) {

    string eile;
    int eilesNr = 1;
    ifstream fd ("test.txt");

    if (!fd.is_open())
    {
        cerr << "Nepavyko atidaryti failo\n";
        return;
    }

    while (getline(fd, eile))
    {
        stringstream ss(eile);
        string zodis;
        while (ss>>zodis){
            if (yraURL(zodis)){
                urls.insert(zodis);
        }else {
            string istrintas = istrintiZodi(zodis);
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
//--------------------------------------------------------------------
int main() {

    map<string, int> zodziuSkaicius;
    map<string, set<int>> zodziuEiles;
    set<string> urls;

    failoSkaitymas(zodziuSkaicius, zodziuEiles, urls);
    rasoZodziuSkaiciu(zodziuSkaicius, "Zodziu_skaicius.txt");
    CrossReference(zodziuEiles,zodziuSkaicius, "Cross_reference.txt");
    rasoURL(urls, "URLs.txt");

    return 0;
}
