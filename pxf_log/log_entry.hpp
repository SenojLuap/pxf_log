#pragma once

#include <string>
#include "pxf_log/severity.hpp"

namespace PXFLOG {

    struct log_entry {
        std::string message;
        entry_severity severity;

        log_entry(std::string message, entry_severity severity);

        std::string output();
    };
}