#include "TestServer.hpp"

#include<unistd.h>
#include <string.h>
#include "SimpleServer.hpp"



HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10){
    launch();
}
void HDE::TestServer::acceptor(){
    struct sockaddr_in address = get_socket() ->get_address();
    int addrelen = sizeof(address); 
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address , (socklen_t *)&addrelen);
    read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler(){
     std::cout << buffer << std::endl;
}

void HDE::TestServer::responder(){
    char *message  = "Hello from server";
    send(new_socket,message, strlen(message), 0);
    close(new_socket);
}

void HDE::TestServer::launch(){
    while(true){
           std::cout << "===== WAITING ======" << std::endl;
        acceptor();
        handler();
        responder();
           std::cout << "===== DONE ======" << std::endl;
    }
}