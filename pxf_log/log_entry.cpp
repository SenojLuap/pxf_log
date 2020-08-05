#include "log_entry.hpp"

namespace PXFLOG {

    log_entry::log_entry(std::string message, entry_severity severity) : message(message), severity(severity) { }

    std::string log_entry::output() {
        // TODO
        return "cats";
    }
}