#pragma once

#include <cstdint>

namespace PXFLOG {
    enum entry_severity : uint8_t {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };
}