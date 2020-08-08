#pragma once

#include <memory>
#include <string>

#include "pxf_log/log_config.hpp"
#include "pxf_log/severity.hpp"

namespace PXFLOG {

    // Internal
    class log_session;
    class log_queue;

    class pxf_log {
    public:

        log_config config;

        pxf_log();
        ~pxf_log();

        void start(bool reset_log_file = false);
        void shutdown();

        void log(entry_severity severity, std::string message);

    private:
        std::unique_ptr<std::thread> log_thread;
        std::unique_ptr<log_queue> message_queue;
    };
    
}