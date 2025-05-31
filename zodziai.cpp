#include "my.h"

void rasoZodziuSkaiciu( map<string, int>& zodziuSkaicius, string filename){
    ofstream fr (filename);
    if (!fr.is_open()) {
    cerr << "Failed to open 1" << filename << " for writing.\n";
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
void CrossReference(map<string, set<int>>& zodziuEiles, map<string, int>& zodziuSkaicius, string filename){
    ofstream fr (filename);
    if (!fr.is_open()) {
    cerr << "Failed to open 2" << filename << " for writing.\n";
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
void rasoURL(set<string>& urls, string filename){
    ofstream fr (filename);
    if (!fr.is_open()) {
    cerr << "Failed to open 3 " << filename << " for writing.\n";
    return;
}

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
    //return false;
}

//--------------------------------------------------------------------
void failoSkaitymas(map<string, int>& zodziuSkaicius,
                    map<string, set<int>>& zodziuEiles,
                    set<string>& urls) {

    string eile;
    int eilesNr = 1;
    //cout << "Opening file..." << endl;

    ifstream fd ("tekstas.txt");

    if (!fd.is_open())
    {
        cerr << "Nepavyko atidaryti failo\n";
        //system("pause");
        //exit(1);
        //return;
    }

    //cout << "File opened successfully." << endl;
    while (getline(fd, eile))
    {
        //cout << "Reading line: " << eile << endl;  
        stringstream ss(eile);
        string zodis;
        while (ss>>zodis){
             //cout << "Found word: " << zodis << endl;

            if (yraURL(zodis)){
                 // cout << "It's a URL." << endl;
                urls.insert(zodis);
        }else {
            string istrintas = istrintiZodi(zodis);
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
    //  std::locale::global(std::locale("en_US.UTF-8"));
    //std::cout << "Program started.\n";
    //system("pause");
    //SetConsoleOutputCP(CP_UTF8);
    map<string, int> zodziuSkaicius;
    map<string, set<int>> zodziuEiles;
    set<string> urls;

    failoSkaitymas(zodziuSkaicius, zodziuEiles, urls);
    rasoZodziuSkaiciu(zodziuSkaicius, "Zodziu_skaicius.txt");
    CrossReference(zodziuEiles,zodziuSkaicius, "Cross_reference.txt");
    rasoURL(urls, "URLs.txt");

    system("pause");
    return 0;
}
