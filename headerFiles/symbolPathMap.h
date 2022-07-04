#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#pragma once

using namespace std;

class SymbolPathMap
{
private:
    SymbolPathMap() {}
    static SymbolPathMap instance;

public:
    static SymbolPathMap& getinstance();

    // Declaring the type and name of the vector
    static unordered_map<string, string> umap;

    // a func that creats a map, and inserts a given key and a given value.
    static void symbolPathMap(const string &key, const string &value);
};
