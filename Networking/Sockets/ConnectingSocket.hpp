#ifndef ConnectingSocket_H
#define ConnectingSocket_H


#include "SimpleSocket.hpp"

namespace HDE{
    class ConnectingSocket : public SimpleSocket{
        public:

            ConnectingSocket(int domain, int service, int protocal, u_short port, u_long localIP);
            int connect_to_network(int sock, struct sockaddr_in address);
    };
}



#endif // ConnectingSocket_H