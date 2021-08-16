//
// Created by trol53 on 07.07.2021.
//

#include "headers/server.h"
#include <iostream>

void Server::Run() {
    std::string recv_mess;
    while (true){
            recv_mess = sock.RecvMessage();
            if (recv_mess == "exit")
                break;
            Solve solve(recv_mess);
            solve.Run();
            sock.SendMessage("Ok\n");
            sock.Close();
            sock.Accept();
    }
}

