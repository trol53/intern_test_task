//
// Created by trol53 on 07.07.2021.
//

#include "headers/sock.h"

Socket::Socket() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(3333);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    connect(sock, (struct sockaddr*)&addr, sizeof(addr));
}

std::string Socket::RecvMessage() {

    recv(sock, get_mess, 2048, 0);
    return get_mess;
}

void Socket::SendMessage(std::string send_mess) {
    send(sock, send_mess.data(), send_mess.size() + 1, 0);
}

Socket::~Socket() {
    close(sock);
}