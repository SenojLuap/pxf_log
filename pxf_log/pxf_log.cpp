#include "pxf_log/pxf_log.hpp"

#include "log_queue.hpp"
#include "log_session.hpp"

namespace PXFLOG {

    void log_thread(log_queue* queue) {
        bool working = true;
        while (working) {
            // INFINITE LOOP! DOOOOOMMMM!!!
        }
    }


    pxf_log::pxf_log() : session(nullptr) {
    }


    pxf_log::~pxf_log() {
        shutdown();
    }


    void pxf_log::start() {
        if (session == nullptr) {
            auto queue = new log_queue();
            auto thread = new std::thread(log_thread, queue);
            session = std::make_unique<log_session>(thread, queue);
        }
    }


    void pxf_log::shutdown() {
        if (session != nullptr) {
            session->event_queue->push(log_event::shutdown_event());
            session->thread->join();
            session = nullptr;
        }
    }
}