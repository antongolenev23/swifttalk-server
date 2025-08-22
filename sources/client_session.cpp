#include "client_session.hpp"
#include <iostream>

namespace echo_server {

ClientSession::ClientSession(std::unique_ptr<Connection> conn)
    : conn_(std::move(conn)) {}
    
void ClientSession::start() {
    std::cout << "Session started\n";
    receive_message();
}

void ClientSession::stop() {
    std::cout << "Session stopped\n";
    conn_->close();
}

void ClientSession::receive_message() {
    try {
        std::string data = conn_->read();
        std::cout << "Received from client: " << data << "\n";
        send_message(Message(data));
    } catch (const std::exception& e) {
        std::cerr << "Handle incoming error: " << e.what() << "\n";
        stop();
    }
}

void ClientSession::send_message(const Message& msg) {
    conn_->write(msg.text() + "\n");
}

} // namespace echo_server
