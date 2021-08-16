#ifndef SOCK_H
#define SOCK_H

#include <string>
#include <zmq.hpp>

class Message {

    
public:

    static std::string GetString(zmq::message_t& mess);

    static zmq::message_t MakeMessage(std::string &str);

};

class Socket{

    public:
    Socket(zmq::socket_type type);

    ~Socket();

    void SendMessage(std::string msg, zmq::send_flags flag);

    std::string RecvMessage ();

protected:

    zmq::context_t* cont;
    zmq::socket_t* sock;
    zmq::socket_type type_sock;

};

class ReqSocket : public Socket{
    public:
    ReqSocket();

    ~ReqSocket();

    void Bind(int port);


    protected:
    int port_;

};

class RepSocket : public Socket{
    public:
    RepSocket ();

    ~RepSocket();

    void Connect(int port);

    protected:
    int port_;
};



#endif



