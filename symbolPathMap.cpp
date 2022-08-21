#include "headerFiles/symbolPathMap.h"

// singelton
SymbolPathMap SymbolPathMap::instance ;
SymbolPathMap& SymbolPathMap::getinstance()
{
    return instance;
}

unordered_map<string, string> SymbolPathMap::umap;

void SymbolPathMap::symbolPathMap(const string &key, const string &value)
{
    umap.insert({key, value});
};

