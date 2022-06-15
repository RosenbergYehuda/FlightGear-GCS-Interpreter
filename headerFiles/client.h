#pragma once
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Client
{
private:
    static Client *instance;

public:
    int sock = 0, valread;
    char buffer[1024] = {0};

    static Client *getinstance();

    // a func that sets up the client side
    int client(string IP, string port);

    // a func that uses the previos func, to send a message to the server, and recive the answer.
    void send(char *message);
};
