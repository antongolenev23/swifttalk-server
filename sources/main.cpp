#include "server.hpp"

int main() {
    echo_server::Server s(8080);
    s.start();
}
