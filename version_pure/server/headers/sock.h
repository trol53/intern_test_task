//
// Created by trol53 on 07.07.2021.
//

#ifndef SERVER_SOCK_H
#define SERVER_SOCK_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

class Socket{
private:
    int sock;
    int listiner;
    struct sockaddr_in addr;
    char get_mess[2048];
public:
    Socket();

    std::string RecvMessage();

    void SendMessage(std::string send_mess);
    void Accept();
    void Close();
    ~Socket();

};

#endif //SERVER_SOCK_H
