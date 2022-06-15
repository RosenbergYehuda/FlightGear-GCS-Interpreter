#include "headerFiles/toolBox.h"

double ToolBox::getStatus(string var)
{
    double ret;
    if (var == "h0")
    {
        string strVal = SymbolPathMap::getinstance().umap.at(var);

        // convert from string to double
        ret = stod(strVal);
    }
    else
    {
        string path = SymbolPathMap::getinstance().umap.at(var);
        ret = PathValueMap::getinstance()->umap.at(path);
    }
    return ret;
};

bool ToolBox::operatorInterp(double x, string op, string yStr)
{
    // converting the string to an int
    int y = stoi(yStr);
    if ((op == "==") && (x == y))
        return true;
    else if ((op == "!=") && (x != y))
        return true;
    else if ((op == "<") && (x < y))
        return true;
    else if ((op == ">") && (x > y))
        return true;
    else if ((op == "<=") && (x <= y))
        return true;
    else if ((op == ">=") && (x >= y))
        return true;
    else
        return false;
};

void ToolBox::systemRun()
{
    system("fgfs --telnet=socket,in,10,127.0.0.1,5402,tcp --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small");
};

pair<vector<vector<string>>, vector<vector<string>>> ToolBox::combine(vector<vector<string>> vec1, vector<vector<string>> vec2)
{
    return std::make_pair(vec2, vec1);
};

vector<string> ToolBox::replaceByStatus(vector<string> line)
{
    ToolBox toolsInstance;
    for (int i = 2; i < line.size(); i++)
    {
        string word = line[i];

        // checking if the word is a var type that i need to get its status
        if (SymbolPathMap::getinstance().umap.find(word) != SymbolPathMap::getinstance().umap.end())
        {
            // getting its status
            double dValue = toolsInstance.getStatus(word);

            // converting the status from double to string
            string strValue = to_string(dValue);

            // replacing the original word by its status as a string
            line[i] = strValue;
        }
    }
    return line;
};

// dose not work!!!
/*
bool ToolBox::isFound(string element, class claasName)
{
    if(claasName::getinstance()->umap.find(line[1]) == claasName::getinstance()->umap.end())
    {
        return false;
    }
    else{
        return true;
    }
};
*/
/*
int main()
{
    ToolBox tinstance;
    cout<<tinstance.operatorInterp(5,"<", 3)<<endl;
    return 0;
};
*/