#include <iostream>
#include "headerFiles/lexer.h"
#include "headerFiles/commandMap.h"
#include "headerFiles/command.h"
#include <stdint.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // get the text from the lexer
    pair<vector<vector<string>>, vector<vector<string>>> myPair = Lexer::getinstance().lexingMethod("my_file.txt");
    vector<vector<string>> mainVec = myPair.first;

    // loop over each vector (AKA line)
    for (int i = 0; i < mainVec.size(); i++)
    {
        vector<string> line = mainVec[i];

        // sending the command word to activate its command class via the command map,
        // and fedding the polimorphic "do command" whith the entire line of text

        // checking if the command is not in the command map (that means it is a set type)
        CommandMap commandMapInstance;
        if (commandMapInstance.umap.find(line[0]) == commandMapInstance.umap.end())
        {
            commandMapInstance.umap["set"]->doCommand({line});
        }
        else
        {
            commandMapInstance.umap[line[0]]->doCommand({line});
        }
    }
    return 0;
}