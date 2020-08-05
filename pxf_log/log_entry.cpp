#include "log_entry.hpp"

#include <sstream>
#include <cstdio>

namespace PXFLOG {

    log_entry::log_entry(std::string message, entry_severity& severity, time_t& time, std::string log_name) : message(message), severity(severity), time(time), log_name(log_name) { }

    std::string log_entry::output() {
        std::stringstream res;

        res << "[" << log_name << " | ";

        auto* local = localtime(&time);
        char time_buffer[10];
        sprintf(time_buffer, "%02u:%02u:%02u]", local->tm_hour, local->tm_min, local->tm_sec);
        res << time_buffer;

        res << "<" << severity_to_string(severity) << "> ";

        res << message;
        return res.str();
    }
}