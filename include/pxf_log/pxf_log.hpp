#pragma once

#include <memory>

namespace PXFLOG {

    // Internal
    class log_session;

    class pxf_log {

        pxf_log();
        ~pxf_log();

        void start();
        void shutdown();

    private:
        std::unique_ptr<log_session> session;
    };
    
}