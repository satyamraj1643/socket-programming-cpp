#ifndef TESTSERVER_HPP_
#define TESTSERVER_HPP_


#include "SimpleServer.hpp"




namespace HDE {

    class TestServer : public SimpleServer {
        private:
            char buffer[30000] = {0};
            int new_socket;
            std::string route;
           

        public:
            TestServer();
            void acceptor();
            void handler();
            void responder();
            void launch();
    };
}



#endif // TESTSERVER_HPP_