#ifndef ACCEPTOR_H
#define ACCEPTOR_H

#include <memory>
#include <functional>


namespace MiniHttp { namespace Base {

class EventLoop;
class Channel;
class Socket;

class Acceptor {
public:
    explicit Acceptor(std::shared_ptr<EventLoop>, std::unique_ptr<Socket>);
    Acceptor(const Acceptor &) = delete;
    Acceptor & operator=(const Acceptor &) = delete;
    ~Acceptor();
    std::shared_ptr<Channel> getChannel() const {
        return channel;
    }
    void connectCallback() const;
    void accept() const;

private:

    std::unique_ptr<Socket> socket;
    std::shared_ptr<EventLoop> eventLoop;
    std::shared_ptr<Channel> channel;
};

}}

#endif /* ACCEPTOR_H */
