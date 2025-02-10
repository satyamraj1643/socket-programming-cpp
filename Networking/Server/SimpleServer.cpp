#include "SimpleServer.hpp"


HDE::SimpleServer::SimpleServer(int domain, int service, int protocal, u_short port, u_long localIp, int backlog){
      socket = new ListeningSocket(domain, service, protocal, port, localIp, backlog);
      delete socket;
}

HDE::ListeningSocket *HDE::SimpleServer::get_socket()
{
    return socket;
}
