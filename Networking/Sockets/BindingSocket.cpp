#include "BindingSocket.hpp"

HDE::BindingSocket::BindingSocket(int domain, int service, int protocal, u_short port, u_long localIP)
    : SimpleSocket(domain, service, protocal, port, localIP){
        int connection  = connect_to_network(get_sock(), get_address());
        set_connection(connection);
        test_connection(get_connection());
    }


int HDE::BindingSocket::connect_to_network(int sock, struct sockaddr_in address){
    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}