#include "headerFiles/commandMap.h"

// Constractor
CommandMap::CommandMap()
{
    // Inserting values by using [] operator
    umap["openDataServer"] = std::make_unique <ServerCommand>();
    umap["connect"] = std::make_unique<ClientCommand>();
    umap["var"] = std::make_unique<VarCommand>();
    umap["set"] = std::make_unique<SetCommand>();
    umap["while"] = std::make_unique<WhileCommand>();
    umap["print"] = std::make_unique<PrintCommand>();
    umap["sleep"] = std::make_unique<SleepCommand>();
};

unordered_map<string, unique_ptr <Command>> CommandMap::umap;


/*
int main()
{
    CommandMap instance;
    cout<<instance.umap.at("openDataServer")<<endl;
    return 0;
}
*/