//
// Created by trol53 on 06.07.2021.
//
#include "headers/sock.hpp"


const std::string CONNECT_PREFIX =  "tcp://localhost:";
const std::string BIND_PREFIX  = "tcp://*:";

Socket::Socket(zmq::socket_type type) : cont(new zmq::context_t(1)), sock(new zmq::socket_t(*cont, type)), type_sock(type) {}

Socket::~Socket(){
    delete sock;
    delete cont;
}

std::string  Message::GetString(zmq::message_t& mess){
    return std::string ((const char*)mess.data(), mess.size());
}

zmq::message_t Message::MakeMessage(std::string &str){
    zmq::message_t msg(str.size());
    memcpy(msg.data(), str.c_str(), str.size());
    return msg;
}

void Socket::SendMessage(std::string msg, zmq::send_flags flag) {
    zmq::message_t mess = Message::MakeMessage(msg);
    sock->send(mess, flag);
}

std::string Socket::RecvMessage (){
    zmq::message_t mess;
    auto buff = sock->recv(mess);
    return Message::GetString(mess);
}

ReqSocket::ReqSocket() : Socket(zmq::socket_type::req) {}
ReqSocket::~ReqSocket(){
   // sock->unbind(BIND_PREFIX + std::to_string(port_));
}

void ReqSocket::Bind(int port){
    port_ = port;
    sock->bind(BIND_PREFIX + std::to_string(port));
}

RepSocket::RepSocket () : Socket(zmq::socket_type::rep){}

RepSocket::~RepSocket(){
    sock->disconnect(CONNECT_PREFIX + std::to_string(port_));
}

void RepSocket::Connect(int port){
    sock->connect(CONNECT_PREFIX + std::to_string(port));
}
