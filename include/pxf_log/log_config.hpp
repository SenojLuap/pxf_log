#pragma once

#include <string>
#include <chrono>

using namespace std::string_literals;

namespace PXFLOG {
    struct log_config {
        std::string name;
        float file_flush_interval;

        log_config(std::string name, float file_flush_interval) : name(name), file_flush_interval(file_flush_interval) { }
        log_config() : name("LOG"s), file_flush_interval(0.5f) { }
    };
}