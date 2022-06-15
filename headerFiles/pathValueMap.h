#include <iostream>
#include <unordered_map>
#include <vector>
#pragma once

using namespace std;

class PathValueMap
{
private:
    static PathValueMap *instance;

public:
    static PathValueMap *getinstance();

    // Declaring umap type and name
    static unordered_map<string, double> umap;

    static void pathValueMap(vector<double> values);
};