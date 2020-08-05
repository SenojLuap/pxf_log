#include "log_entry.hpp"

#include <sstream>

namespace PXFLOG {

    log_entry::log_entry(std::string message, entry_severity severity) : message(message), severity(severity) { }

    std::string log_entry::output() {
        std::stringstream res;
        res << "[" << severity_to_string(severity) << "] ";
        res << message;
        return res.str();
    }
}