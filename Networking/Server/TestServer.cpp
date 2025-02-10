#include "TestServer.hpp"
#include <unistd.h>
#include <string.h>
#include <iostream>
#include "SimpleServer.hpp"

HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 8053, INADDR_ANY, 10) {
    launch();
}

void HDE::TestServer::acceptor() {
    struct sockaddr_in address = get_socket()->get_address();
    int addrelen = sizeof(address);
    new_socket = accept(get_socket()->get_sock(), (struct sockaddr *)&address, (socklen_t *)&addrelen);
    read(new_socket, buffer, 30000);
}

void HDE::TestServer::handler() {
    std::cout << buffer << std::endl;
}

void HDE::TestServer::responder() {
    // Create an HTML response
    const char *html_content = "<!DOCTYPE html>"
                               "<html>"
                               "<head><title>Satyam's Server</title></head>"
                               "<body>"
                               "<h1>Hello from the server!</h1>"
                               "<p>This is an HTML response.</p>"
                               "</body>"
                               "</html>";

    // Create an HTTP response with Content-Type: text/html
    std::string http_response = "HTTP/1.1 200 OK\r\n";
    http_response += "Content-Type: text/html\r\n";
    http_response += "Content-Length: " + std::to_string(strlen(html_content)) + "\r\n";
    http_response += "\r\n"; // End of headers
    http_response += html_content;

    // Send the HTTP response
    send(new_socket, http_response.c_str(), http_response.size(), 0);

    // Close the socket
    close(new_socket);
}

void HDE::TestServer::launch() {
    while (true) {
        std::cout << "===== WAITING ======" << std::endl;
        acceptor();
        handler();
        responder();
        std::cout << "===== DONE ======" << std::endl;
    }
}