#include "ListeningSocket.hpp"

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocal, u_short port, u_long localIP, int backlog)
 :BindingSocket(domain, service, protocal, port, localIP) {
        this->backlog = backlog;
        start_listening();
        test_connection(this->listening);
}

void HDE::ListeningSocket::start_listening(){
    this->listening = listen(get_sock(), backlog);
}