#ifndef SimpleSocket_hpp
#define SimpleSocket_hpp

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<iostream>


namespace HDE{
    class SimpleSocket{
        private:
            struct sockaddr_in  address;
            int sock;
            int connection;

        public:
            SimpleSocket(int domain, int service, int protocal, u_short port, u_long localIP);
            int virtual connect_to_network(int sock, struct sockaddr_in  address) = 0; 
            void test_connection(int);
            struct sockaddr_in get_address();
            int get_sock();
            int get_connection();
            void set_connection(int);
    };
}



#endif 