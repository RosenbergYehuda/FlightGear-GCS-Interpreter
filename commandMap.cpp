#include "headerFiles/commandMap.h"

// Constractor
CommandMap::CommandMap()
{
    // Inserting values by using [] operator
    umap["openDataServer"] = make_unique <ServerCommand>();
    umap["connect"] = make_unique<ClientCommand>();
    umap["var"] = make_unique<VarCommand>();
    umap["set"] = make_unique<SetCommand>();
    umap["while"] = make_unique<WhileCommand>();
    umap["print"] = make_unique<PrintCommand>();
    umap["sleep"] = make_unique<SleepCommand>();
};

unordered_map<string, unique_ptr <Command>> CommandMap::umap;

