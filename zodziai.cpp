#include "my.h"

void rasoZodziuSkaiciu(map<string, set<int>>& zodziuEiles,
                    map<string, int>& zodziuSkaicius, string filename){

}

void CrossReference(map<string, set<int>>& zodziuEiles,
                    map<string, int>& zodziuSkaicius, string filename){

}

void rasoURL(set<string>& urls, string filename){

}

string istrintiZodi(string& zodis){

    string istrintas;
    for(char zd : zodis) {
        if (isalpha(zd) || isdigit(zd)) {
            istrintas += tolower(zd);
        }
    }
    return istrintas;
}
//--------------------------------------------------------------------
bool yraURL (const string zodis){

}
//--------------------------------------------------------------------
void failoSkaitymas(map<string, int>& zodziuSkaicius,
                    map<string, set<int>>& zodziuEiles,
                    set<string>& urls) {

    string eile;
    int eilesNr = 1;
    ifstream fd ("tekstas.txt");

    if (!fd)
    {
        cerr << "Nepavyko atidaryti failo\n";
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
            if(!istrintas.empty()) {
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
    rasoZodziuSkaiciu(zodziuEiles, zodziuSkaicius, "Zodziu_skaicius.txt");
    CrossReference(zodziuEiles,zodziuSkaicius, "Cross_reference.txt");
    rasoURL(urls, "URLs.txt");

    return 0;
}
