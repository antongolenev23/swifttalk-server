#pragma once
#include "client_session.hpp"
#include <boost/asio.hpp>
#include <thread>
#include <mutex>

namespace echo_server {

class Server {
public:
    explicit Server(uint32_t port);
    void start();
    void stop();
    void accept_client();

private:
    uint32_t port_;
    bool running_;
    boost::asio::io_context io_;
    boost::asio::ip::tcp::acceptor acceptor_;
    std::mutex sessions_mutex_;
};

} // namespace echo_server

