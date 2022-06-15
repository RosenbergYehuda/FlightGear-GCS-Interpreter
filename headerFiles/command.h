#include <iostream>
#include <vector>
#include "server.h"
#include "client.h"
#include "symbolPathMap.h"
#include "pathValueMap.h"
#include <sstream>
#include <string>
#include <algorithm>
#include "toolBox.h"
#include "lexer.h"
#include <chrono>
#include <thread>
//#include "../shuntingYard.cpp"
#pragma once

using namespace std::literals::chrono_literals;
using namespace std;

// Base class
class Command
{
public:
    virtual void doCommand(vector<string> line) = 0;
};

// Derived class Server
class ServerCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class Client
class ClientCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class Var
class VarCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class Set
class SetCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class While
class WhileCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class Print
class PrintCommand : public Command
{
public:
    void doCommand(vector<string> line);
};

// Derived class Sleep
class SleepCommand : public Command
{
public:
    void doCommand(vector<string> line);
};
