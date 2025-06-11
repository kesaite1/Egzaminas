#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void rasoZodziuSkaiciu( map<wstring, int>& zodziuSkaicius, wstring filename);
void CrossReference(map<wstring, set<int>>& zodziuEiles, map<wstring, int>& zodziuSkaicius, wstring filename);
void rasoURL(set<wstring>& urls, wstring filename);
wstring istrintiZodi(wstring& zodis);
bool yraURL(const wstring& zodis);
void failoSkaitymas(map<wstring, int>& zodziuSkaicius, map<wstring, set<int>>& zodziuEiles, set<wstring>& urls);


#endif