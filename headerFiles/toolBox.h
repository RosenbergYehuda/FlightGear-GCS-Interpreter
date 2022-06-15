#include <iostream>
#include <utility>
#include <vector>
#include "symbolPathMap.h"
#include "pathValueMap.h"
#pragma once

using namespace std;
class ToolBox
{
public:
    // a func that returns the status of a var. the func will go thru both maps in order to
    // return a answer.
    double getStatus(string var);

    // a boolian func that returns true if the given element appiars in the given unordered map.
    bool isFound(string element, class className);

    // a boolian func that interpretes string operators
    bool operatorInterp(double x, string op, string yStr);

    // a func that recives two vectors of vectors of strings, and pairs them together to return
    pair<vector<vector<string>>, vector<vector<string>>> combine(vector<vector<string>> vec1, vector<vector<string>> vec2);

    // a func that starts the drone
    static void systemRun();

    //a func that replaces the variables by there corrent ststus
    vector<string> replaceByStatus(vector<string> line);
};
