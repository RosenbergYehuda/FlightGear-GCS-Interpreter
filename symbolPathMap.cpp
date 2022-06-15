#include "headerFiles/symbolPathMap.h"

// singel tone
SymbolPathMap *SymbolPathMap::instance = 0;
SymbolPathMap *SymbolPathMap::getinstance()
{
    if (instance == 0)
    {
        instance = new SymbolPathMap();
    }
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