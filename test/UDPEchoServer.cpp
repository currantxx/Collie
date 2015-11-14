#include "../include/udp/UDPSocket.hpp"
#include "../include/udp/UDPServer.hpp"
#include "../include/SocketAddress.hpp"
#include "../include/Global.hpp"

using Collie::UDP::UDPServer;
using namespace Collie;

int
main(int argc, char * argv[]) {
    auto & logger = Logger::LogHandler::getHandler();
    logger.setLogLevel(TRACE);
    logger.init();

    unsigned port = 8080;
    if(argc == 2) port = std::stoul(argv[1]);

    UDPServer server;
    server.bind("127.0.0.1", port);
    server.setConnectCallback([&server](const std::string & content,
                                        std::shared_ptr<SocketAddress> addr) {
        const auto res = "From UDP Echo Server: " + content;
        server.send(content, addr);
    });
    server.start();
    return 0;
}
