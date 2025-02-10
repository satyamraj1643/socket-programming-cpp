#include "ConnectingSocket.hpp"


HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int portocal, u_short port, u_long localIP)
    : SimpleSocket(domain, service, portocal, port, localIP){
        int connection  = connect_to_network(get_sock(), get_address());
        set_connection(connection);
        test_connection(get_connection());
    }


int HDE::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address){
    return connect(sock, (struct sockaddr *)&address, sizeof(address));
}