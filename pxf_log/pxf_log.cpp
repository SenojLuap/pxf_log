#include "pxf_log/pxf_log.hpp"

#include <chrono>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdio>
#include <ctime>

#include "log_queue.hpp"

using namespace std::chrono;
using namespace std::string_literals;

namespace PXFLOG {

    bool log_to_file(std::vector<std::string>& messages, std::string& file_name) {
        std::ofstream out_file;
        out_file.open(file_name.c_str(), std::ofstream::out | std::ofstream::app);

        if (!out_file.good()) return false;

        for (auto& message : messages) out_file << message << std::endl;
        out_file.close();

        return true;
    }


    void log_thread_func(log_config config, log_queue* queue) {

        int32_t millisecond_interval = (int32_t)(config.file_flush_interval * 1000);
        std::chrono::milliseconds file_flush_timeout(millisecond_interval);
        std::chrono::milliseconds sleep_time(file_flush_timeout.count() / 4);

        auto time = steady_clock::now();
        log_event next_event;
        std::vector<std::string> pending_log_file;
        while (true) {
            if (queue->pop(&next_event)) {
                if (next_event.entry == nullptr) {
                    break;
                } else {
                    std::string msg = next_event.entry->output();
                    if (config.console_output_enabled[next_event.entry->severity])
                        std::cout << msg << std::endl;
                    if (config.file_output_enabled[next_event.entry->severity])
                        pending_log_file.push_back(msg);
                }
            } else { // No events. Sleep.
                std::this_thread::sleep_for(sleep_time);
            }
            if ((steady_clock::now() - time) >= file_flush_timeout) {
                if (!pending_log_file.empty() && !log_to_file(pending_log_file, config.file_name)) {
                    std::cerr << "Failed to write to log file. File logging disabled" << std::endl;
                    config.file_output_enabled = std::vector<bool>(5, false);
                    pending_log_file.clear();
                }
                time = steady_clock::now();
            }
        }
        if (!pending_log_file.empty())
            log_to_file(pending_log_file, config.file_name);
    }


    pxf_log::pxf_log() : log_thread(nullptr), message_queue(nullptr) {
    }


    pxf_log::~pxf_log() {
        shutdown();
    }


    void pxf_log::start(bool reset_log_file) {
        if (log_thread == nullptr) {

            if (reset_log_file) {
                remove(config.file_name.c_str());
            }

            message_queue = std::make_unique<log_queue>();
            log_thread = std::make_unique<std::thread>(log_thread_func, config, message_queue.get());
        }
    }


    void pxf_log::shutdown() {
        if (log_thread != nullptr) {
            message_queue->push(log_event::shutdown_event());
            log_thread->join();
            log_thread = nullptr;
            message_queue = nullptr;
        }
    }


    void pxf_log::log(entry_severity severity, std::string message) {
        time_t time_now = time(nullptr);
        if (log_thread == nullptr)
            throw std::runtime_error("Attempted to emit log entry before log was running");
        auto entry = std::make_shared<log_entry>(message, severity, time_now, config.name);
        message_queue->push(log_event(entry));
    }
}