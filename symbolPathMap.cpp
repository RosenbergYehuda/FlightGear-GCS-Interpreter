#include "headerFiles/symbolPathMap.h"

// singelton
SymbolPathMap SymbolPathMap::instance ;
SymbolPathMap& SymbolPathMap::getinstance()
{
    return instance;
}

unordered_map<string, string> SymbolPathMap::umap;

void SymbolPathMap::symbolPathMap(string key, string value)
{
    umap.insert({key, value});
};

/*
int main()
{
    SymbolPathMap::getinstance()->symbolPathMap("a","b");

    if (SymbolPathMap::getinstance()->umap.find("23") == SymbolPathMap::getinstance()->umap.end())
        cout << "Element Not Present\n";
    else
        cout << "Element Present\n";

    cout<<SymbolPathMap::getinstance()->umap["a"]<<endl;
    //return "0";
}
*/