#ifndef SIMPLESERVER_HPP_
#define SIMPLESERVER_HPP_

#include "../hdelibc-networking.hpp"


namespace HDE {

    class SimpleServer {

        private:
            ListeningSocket* socket;

        public:
            SimpleServer(int domain, int service, int protocal, u_short port, u_long localIP, int backlog);
            virtual void acceptor() = 0;
            virtual void handler() = 0;
            virtual void responder()= 0;
            virtual void launch() = 0;

            ListeningSocket* get_socket();
    };
}



#endif // SIMPLESERVER_HPP_