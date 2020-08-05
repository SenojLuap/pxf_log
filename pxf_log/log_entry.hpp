#pragma once

#include <string>
#include <ctime>
#include "pxf_log/severity.hpp"

namespace PXFLOG {

    struct log_entry {
        std::string message;
        entry_severity severity;
        time_t time;
        std::string log_name;

        log_entry(std::string message, entry_severity& severity, time_t& time, std::string log_name);

        std::string output();
    };
}