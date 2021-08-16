//
// Created by trol53 on 06.07.2021.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include "sock.hpp"
#include "solve.h"

class Server{
public:

    Server(int port);

    void Run();

private:
    int port;
    RepSocket sock;
};

#endif //SERVER_SERVER_H
