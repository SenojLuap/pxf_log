#include "pxf_log/pxf_log.hpp"

#include <chrono>
#include <vector>
#include <string>
#include <iostream>

#include "log_queue.hpp"
#include "log_session.hpp"

using namespace std::chrono;
using namespace std::string_literals;

namespace PXFLOG {

    void log_to_file(std::vector<std::string>& messages, std::string& file_name) {
        // TODO
    }


    void log_thread(log_config config, log_queue* queue) {

        int32_t millisecond_interval = (int32_t)(config.file_flush_interval * 1000);
        std::chrono::milliseconds file_flush_timeout(millisecond_interval);

        auto time = steady_clock::now();
        log_event next_event;
        std::vector<std::string> pending_log_file;
        while (true) {
            if (queue->pop(&next_event)) {
                if (next_event.entry == nullptr) {
                    break;
                } else {
                    std::string msg = next_event.entry->output();
                    // TODO: filter on what is enabled
                    std::cout << msg << std::endl;
                    pending_log_file.push_back(msg);
                }
            } else { // No events. Sleep.
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
            }
            if ((steady_clock::now() - time) >= file_flush_timeout) {
                // TODO: Actual file name
                log_to_file(pending_log_file, "TEMP"s);
                pending_log_file.clear();
                time = steady_clock::now();
            }
        }
        if (!pending_log_file.empty())
            // TODO: Actual file name
            log_to_file(pending_log_file, "TEMP"s);
    }


    pxf_log::pxf_log() : session(nullptr) {
    }


    pxf_log::~pxf_log() {
        shutdown();
    }


    void pxf_log::start() {
        if (session == nullptr) {
            auto queue = new log_queue();
            auto thread = new std::thread(log_thread, config, queue);
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