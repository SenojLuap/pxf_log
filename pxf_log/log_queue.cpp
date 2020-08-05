#include "log_queue.hpp"


namespace PXFLOG {

    void log_queue::push(log_event& entry) {
        std::unique_lock<std::mutex> lock(queue_mutex);
        queue.push(entry);
    }


    bool log_queue::pop(log_event* result) {
        if (queue.empty()) return false;
        std::unique_lock<std::mutex> lock(queue_mutex);
        *result = queue.front();
        queue.pop();
        return true;
    }

}