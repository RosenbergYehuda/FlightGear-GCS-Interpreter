#include "headerFiles/commandMap.h"

// Constractor
CommandMap::CommandMap()
{
    // Inserting values by using [] operator
    umap["openDataServer"] = new ServerCommand();
    umap["connect"] = new ClientCommand();
    umap["var"] = new VarCommand();
    umap["set"] = new SetCommand();
    umap["while"] = new WhileCommand();
    umap["print"] = new PrintCommand();
    umap["sleep"] = new SleepCommand();
};

unordered_map<string, Command *> CommandMap::umap;

/*
int main()
{
    CommandMap instance;
    cout<<instance.umap.at("openDataServer")<<endl;
    return 0;
}
*/