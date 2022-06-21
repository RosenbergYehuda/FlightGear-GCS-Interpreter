#pragma once
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include <vector>
#include "pathValueMap.h"

using namespace std ::literals::chrono_literals;
using namespace std;

class Server
{
    public:
    //server func
    void server(string port);

    // this func executes the previous server func in it's own thread.
    void serverThread(string port, string frequency);
    
    // this func separats the values recived from the server and store them in a map
    void updateMap (char (&buffer)[1024]);
};


