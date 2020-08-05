#include "pxf_log/log_config.hpp"

namespace PXFLOG {

    log_config::log_config(std::string name, float file_flush_interval, std::string file_name) :
            name(name),
            console_output_enabled(std::vector<bool>(5, true)),
            file_output_enabled(std::vector<bool>(5, true)),
            file_flush_interval(file_flush_interval),
            file_name(file_name) {
    }
    
    log_config::log_config(std::string name) :
            name(name),
            file_flush_interval(0.5f),
            console_output_enabled(std::vector<bool>(5, true)),
            file_output_enabled(std::vector<bool>(5, false)),
            file_name(""s) {
    }
}