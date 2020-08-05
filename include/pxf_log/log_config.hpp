#pragma once

#include <string>
#include <chrono>
#include <memory>

using namespace std::string_literals;

namespace PXFLOG {
    struct log_config {
        std::string name;

        std::shared_ptr<bool[]> console_output_enabled;
        std::shared_ptr<bool[]> file_output_enabled;

        float file_flush_interval;
        std::string file_name;

        log_config(std::string name, float file_flush_interval, std::string file_name);
        log_config(std::string name = "LOG"s);
    };
}