#include <iostream>
#include <fstream>
#include <vector>
#include "toolBox.h"
#pragma once

using namespace std;
class Lexer
{
public:
    // this func will return a pair of two vectors that contains vectors of strings, the first one
    // without the lines in the while loop body. and the second one onley the lines in the body of the while loop.
    pair<vector<vector<string>>, vector<vector<string>>> lexingMethod(string filename);
};
