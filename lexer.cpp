#include "headerFiles/lexer.h"

Lexer Lexer::instance;
Lexer &Lexer::getinstance()
{
    return instance;
}
pair<vector<vector<string>>, vector<vector<string>>> Lexer::lexingMethod(string filename)
{
    // Initializing
    vector<vector<string>> mainVec, whileVec;
    vector<string> words;
    string lineText, word;
    char ch;

    // Read from the text file
    ifstream MyReadFile(filename);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, lineText))
    {
        int lineSize = lineText.size();
        for (int i = 0; i < lineSize; i++)
        {
            ch = lineText[i];

            // this is needed for the end of the while loop
            if (ch != '}')
            {
                if (ch != ' ')
                {
                    word += ch;
                }

                // if a space was found, push the compleate word into the array.
                if (ch == ' ')
                {
                    words.push_back({word});
                    word = "";
                }

                // if i got to the end of the line, push the entire vector of words into the main vec.
                if (i == lineSize - 1)
                {
                    words.push_back({word});
                    word = "";

                    // capturing the while loop body
                    if (words[0][0] == '\t')
                    {
                        // removing the '\t' from the lines
                        words[0].erase(0, 1);

                        whileVec.push_back(words);
                        words.clear();
                    }
                    else
                    {
                        mainVec.push_back(words);
                        words.clear();
                    }
                }
            }
        }
    }
    // Close the file
    MyReadFile.close();

    // combine bouth of the vectors together
    ToolBox tinstance;
    return tinstance.combine(whileVec, mainVec);
};

/*
int main()
{
    
    pair<vector<vector<string>>, vector<vector<string>>> myPair = Lexer::getinstance().lexingMethod("my_file.txt");
    vector<vector<string>> vec = myPair.second;

    //  Displaying the 2D vector
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    return 0;
};
*/