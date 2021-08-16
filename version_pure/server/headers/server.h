//
// Created by trol53 on 07.07.2021.
//

#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "solve.h"
#include "sock.h"

class Server{
private:
    Socket sock;

public:
    void Run();

};

#endif //SERVER_SERVER_H
