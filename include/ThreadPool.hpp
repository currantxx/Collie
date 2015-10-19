#ifndef COLLIE_THREADPOOL_H
#define COLLIE_THREADPOOL_H

#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <vector>


namespace Collie {

class ThreadPool {
public:
    using Task = std::function<void()>;

    explicit ThreadPool(const unsigned &);
    ThreadPool(const ThreadPool &) = delete;
    ThreadPool & operator=(const ThreadPool &) = delete;
    ~ThreadPool();

    void pushTask();
    void shutDown();

private:
    void runInThread();

    std::mutex tasksMtx;
    std::condition_variable tasksCondition;
    std::vector<std::thread> threadPool;
    std::deque<Task> tasks;
    bool terminate;
};

}

#endif /* COLLIE_THREADPOOL_H */
