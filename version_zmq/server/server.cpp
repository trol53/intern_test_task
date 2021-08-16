//
// Created by trol53 on 06.07.2021.
//

#include "headers/server.h"

Server::Server(int port):  port(port){}

void Server::Run(){
    sock.Connect(port);
    std::string get_mess;
    while (true){
        get_mess = sock.RecvMessage();
        if (get_mess == "exit")
            break;
        Solve s(get_mess);
        s.Run();
        sock.SendMessage("Ok", zmq::send_flags::dontwait);

    }
    sock.SendMessage("Ok", zmq::send_flags::dontwait);
}
