#pragma once

#include <thread>
#include <memory>
#include "log_queue.hpp"

namespace PXFLOG {

    struct log_session {
        std::unique_ptr<std::thread> thread;
        std::unique_ptr<log_queue> event_queue;

        log_session(std::thread* thread, log_queue* event_queue) : thread(std::unique_ptr<std::thread>(thread)), event_queue(std::unique_ptr<log_queue>(event_queue)) { }
    };
}