#pragma once

#include <memory>

#include "pxf_log/log_config.hpp"

namespace PXFLOG {

    // Internal
    class log_session;

    class pxf_log {

        log_config config;

        pxf_log();
        ~pxf_log();

        void start();
        void shutdown();

    private:
        std::unique_ptr<log_session> session;
    };
    
}