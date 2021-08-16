//
// Created by trol53 on 07.07.2021.
//

#ifndef CLIENT_SOCK_H
#define CLIENT_SOCK_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

class Socket{
private:
    int sock;
    struct sockaddr_in addr;
    char get_mess[2048];
public:
    Socket();

    std::string RecvMessage();
    void SendMessage(std::string send_mess);
    ~Socket();

};



#endif //CLIENT_SOCK_H
