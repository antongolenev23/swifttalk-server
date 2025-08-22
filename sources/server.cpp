#include "server.hpp"
#include <iostream>

namespace echo_server {
    
using boost::asio::ip::tcp;

Server::Server(uint32_t port)
    : port_(port),
    running_(false),
    acceptor_(io_, tcp::endpoint(boost::asio::ip::make_address("127.0.0.1"), port)) {}

void Server::start() {
    running_ = true;
    std::cout << "Server started on port " << port_ << "\n";

    while (running_) {
        accept_client();
    }
}

void Server::stop() {
    running_ = false;
    io_.stop();
    std::cout << "Server stopped\n";
}

void Server::accept_client() {
    tcp::socket socket(io_);
    acceptor_.accept(socket);
    std::cout << "Client connected\n";

    auto conn = std::make_unique<Connection>(std::move(socket));
    ClientSession session(std::move(conn));
    session.start(); // Обработка синхронная
} 

} // namespace echo_server

