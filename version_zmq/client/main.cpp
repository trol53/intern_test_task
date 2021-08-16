//
// Created by trol53 on 07.07.2021.
//

#include "headers/sock.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "input directory path\n";
        return 0;
    }
    ReqSocket sock;
    sock.Bind(2222);
    sock.SendMessage(argv[1], zmq::send_flags::none);
    std::string recv_str = sock.RecvMessage();
    return 0;

}
