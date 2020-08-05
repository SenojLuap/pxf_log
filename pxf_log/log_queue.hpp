#pragma once

#include <queue>
#include <mutex>

#include "log_event.hpp"

namespace PXFLOG {

    class log_queue {
    public:
        void push(log_event& entry);
        bool pop(log_event* result);

        log_queue() = default;
    
    private:
        std::queue<log_event> queue;
        std::mutex queue_mutex;
    };
}