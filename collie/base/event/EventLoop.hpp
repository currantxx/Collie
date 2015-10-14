#ifndef COLLIE_BASE_EVENT_EVENTLOOP_H
#define COLLIE_BASE_EVENT_EVENTLOOP_H

#include <memory>
#include <map>


namespace Collie { namespace Base {

namespace Poll {
class Poller;
}

namespace Event {

class Channel;

class EventLoop {
public:

    EventLoop() noexcept;
    EventLoop(const EventLoop &) = delete;
    EventLoop & operator=(const EventLoop &) = delete;
    ~EventLoop();

    void loop();
    void updateChannel(std::shared_ptr<Channel>);  // update or insert
    void removeChannel(std::shared_ptr<Channel>);
    bool hasChannel(std::shared_ptr<Channel>) const;
    void updateChannel(const int fd);  // only update
    void removeChannel(const int fd);

    // link to poller event method
    void enableEventRead(unsigned & events) const noexcept;
    void disableEventRead(unsigned & events) const noexcept;
    void enableEventWrite(unsigned & events) const noexcept;
    void disableEventWrite(unsigned & events) const noexcept;
    bool isEventRead(const unsigned & events) const noexcept;
    bool isEventWrite(const unsigned & events) const noexcept;
    bool isEventError(const unsigned & events) const noexcept;
    bool isEventClose(const unsigned & events) const noexcept;

private:
    using ChannelMap = std::map<int, std::shared_ptr<Channel>>;

    std::unique_ptr<Poll::Poller> poller;
    std::shared_ptr<ChannelMap> channels;
    bool isLooping;
};

}}}

#endif /* COLLIE_BASE_EVENT_EVENTLOOP_H */
