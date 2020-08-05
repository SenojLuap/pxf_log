#pragma once

#include <string>
#include <chrono>
#include <vector>

using namespace std::string_literals;

namespace PXFLOG {
    struct log_config {
        std::string name;

        std::vector<bool> console_output_enabled;
        std::vector<bool> file_output_enabled;

        float file_flush_interval;
        std::string file_name;

        log_config(std::string name, float file_flush_interval, std::string file_name);
        log_config(std::string name = "LOG"s);
        log_config(const log_config& original_log) = default;
    };
}