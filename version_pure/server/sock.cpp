//
// Created by trol53 on 07.07.2021.
//
#include "headers/sock.h"


Socket::Socket(){
    listiner = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3333);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listiner, (struct sockaddr*)&addr, sizeof(addr));
    listen(listiner, 1);
    sock = accept(listiner, NULL, NULL);

}

std::string Socket::RecvMessage() {

    recv(sock, get_mess, 2048, 0);
    return get_mess;
}

void Socket::SendMessage(std::string send_mess) {
    send(sock, send_mess.c_str(), send_mess.size(), 0);
}


void Socket::Close() {
    close(sock);
}

void Socket::Accept(){
    sock = accept(listiner, NULL, NULL);
}

Socket::~Socket(){
    close(sock);
}

