#include <iostream>
#include <unordered_map>
#include <memory>
#include "command.h"
#pragma once

using namespace std;

class CommandMap
{
public:
    // Constractor
    CommandMap();

    // Declaring umap type and name <string, command pointers>
    static unordered_map<string, unique_ptr <Command>> umap;
};
