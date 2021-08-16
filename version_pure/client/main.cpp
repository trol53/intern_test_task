//
// Created by trol53 on 07.07.2021.
//
#include <iostream>
#include "headers/sock.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cout << "input directory\n";
        return 0;
    }
    Socket sock;
    sock.SendMessage(argv[1]);
    sock.RecvMessage();
}
