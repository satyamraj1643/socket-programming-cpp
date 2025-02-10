#ifndef BindingSocket_H
#define BindingSocket_H


#include "SimpleSocket.hpp"

namespace HDE{
    class BindingSocket : public SimpleSocket{
        public:
            BindingSocket(int domain, int service, int protocal, u_short port, u_long localIP);
            int connect_to_network(int sock, struct sockaddr_in address);
            
    };
}


#endif