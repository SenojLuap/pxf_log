#pragma once

#include <memory>

#include "log_entry.hpp"

namespace PXFLOG {

    struct log_event {
        std::shared_ptr<log_entry> entry;

        log_event(std::shared_ptr<log_entry> entry);

        static log_event shutdown_event();
    
    private:
        log_event();
    };
}