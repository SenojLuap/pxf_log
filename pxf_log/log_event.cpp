#include "log_event.hpp"

namespace PXFLOG {

    log_event::log_event(std::shared_ptr<log_entry> entry) : entry(entry) { }

    log_event::log_event() : entry(nullptr) { }

    log_event log_event::shutdown_event() {
        log_event event;
        return event;
    }
}