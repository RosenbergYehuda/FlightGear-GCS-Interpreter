#include "headerFiles/command.h"
#include "headerFiles/commandMap.h"
#include "shuntingYard.cpp"

ToolBox toolsinstance;
Lexer lexInstance;
CommandMap commandMapInstance;
Calculator calInstance;

// Derived class server
void ServerCommand::doCommand(vector<string> line)
{
    Server instance;
    instance.serverThread(line[1], line[2]);

    // sending the system a command (using separated thread) to start the drone separated thread
    thread t2(ToolBox::systemRun);
    t2.detach();

    // taking a nap until the drone is ready
    cout << "Please wait for 30 seconds...\n"
         << endl;
    this_thread::sleep_for(30s);
};

// Derived class client
void ClientCommand::doCommand(vector<string> line)
{
    Client::getinstance().client(line[1], line[2]);
};

// Derived class var
void VarCommand::doCommand(vector<string> line)
{
    // checking is it a bind order or a set order.
    if (line[3] != "bind")
    {
        double dValue = toolsinstance.getStatus(line[3]);

        // converting the double value to a string in order to insert it to a string based map.
        string strValue = to_string(dValue);
        SymbolPathMap::getinstance().symbolPathMap(line[1], strValue);
    }
    else
    {
        SymbolPathMap::getinstance().symbolPathMap(line[1], line[4]);
    }
};

// Derived class set
void SetCommand::doCommand(vector<string> line)
{
    // connecting multiple string to one string
    stringstream ss;
    ss << "set"
       << " " << SymbolPathMap::getinstance().umap.at(line[0]) << " " << line[2] << "\r\n";
    string oneStrings = ss.str();

    // removing the " symbol from the path
    char chars[] = "\"";
    for (unsigned int i = 0; i < strlen(chars); ++i)
    {
        oneStrings.erase(remove(oneStrings.begin(), oneStrings.end(), chars[i]), oneStrings.end());
    }

    // converting the string 'oneString' to a char*
    char *charOneString = &oneStrings[0];

    Client::getinstance().send(charOneString);
};

// Derived class while
void WhileCommand::doCommand(vector<string> line)
{
    // use the second part of the pair, that contains only the while body instructions
    pair<vector<vector<string>>, vector<vector<string>>> myPair = lexInstance.lexingMethod("my_file.txt");
    vector<vector<string>> whileBody = myPair.second;

    // the while condition
    while (toolsinstance.operatorInterp((toolsinstance.getStatus(line[1])), line[2], line[3]))
    {
        // loop over each vector (A.K.A line)
        for (int i = 0; i < whileBody.size(); i++)
        {
            vector<string> line = whileBody[i];

            // checking if the command is not in the command map (not print or sleep etc.)
            if (CommandMap::umap.find(line[0]) == CommandMap::umap.end())
            {
                //replacing the var by its current status
                line = toolsinstance.replaceByStatus(line);

                // connecting multiple string to one string
                string s;
                for (int j = 2; j < line.size(); j++)
                {
                    s += line[j];
                    s += " ";
                }

                // getting the calculation of the string type equasion from the shuntingYard
                double shuntVal = calInstance.calculate(s);

                // converting the duble resulte of the calculation back to string
                string strShuntVal = to_string(shuntVal);

                // pushing all the strings into one vector in order to send it to the client
                vector<string> finalLine;
                finalLine.push_back(line[0]);
                finalLine.push_back(" = ");
                finalLine.push_back(strShuntVal);

                commandMapInstance.umap["set"]->doCommand({finalLine});
            }
            else
            {
                // if it is a commant type, send it the polimorphic doCommand (all the othe classes in this file.)
                commandMapInstance.umap[line[0]]->doCommand({line});
            };
        }
    }
};

// Derived class print
void PrintCommand::doCommand(vector<string> line)
{
    // checking what kind of print is it, a plane text or a status.
    if ((SymbolPathMap::getinstance().umap.find(line[1]) != SymbolPathMap::getinstance().umap.end()))
        cout << "the current " << line[1] << " is: " << toolsinstance.getStatus(line[1]) << endl;
    else
    {
        for (int i = 1; i < line.size(); i++)
            cout << line[i] << " ";
    }
    cout << endl;
};

// Derived class sleep
void SleepCommand::doCommand(vector<string> line)
{
    // converting string to int
    int timeToSleep = stoi(line[1]);
    std::chrono::milliseconds timespan(timeToSleep);
    std::this_thread::sleep_for(timespan);
};

/*
int main()
{

    //this empty loop is needed for keep the server thread alive until the drone connects.
    while (true)
    {

    }
    return 0;
}
*/