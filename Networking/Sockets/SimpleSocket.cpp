#include "SimpleSocket.hpp"

HDE::SimpleSocket ::SimpleSocket(int domain, int service, int protocal, u_short port, u_long localIP){
     
    // Define address structure

     address.sin_family = domain;
     address.sin_port = htons(port);
     address.sin_addr.s_addr = htonl(localIP);

    // Connect with the socket

     sock = socket(domain, service, protocal);
     test_connection(sock);


}


void HDE::SimpleSocket::test_connection(int item_to_test){
        if(item_to_test < 0){
            perror("Failed to connect...");
            exit(EXIT_FAILURE);
        }
}

struct sockaddr_in HDE::SimpleSocket::get_address(){
    return address;
}

int HDE::SimpleSocket::get_sock(){
    return sock;
}

int HDE::SimpleSocket::get_connection(){
    return connection;
}

void HDE::SimpleSocket::set_connection(int conn){
    connection = conn;
}

