#include "pxf_log/log_config.hpp"

namespace PXFLOG {

    log_config::log_config(std::string name, float file_flush_interval, std::string file_name) :
            name(name),
            console_output_enabled(std::shared_ptr<bool[]>(new bool[5])),
            file_output_enabled(std::shared_ptr<bool[]>(new bool[5])),
            file_flush_interval(file_flush_interval),
            file_name(file_name) {
        for (int i = 0; i < 5; i++) {
            console_output_enabled[i] = true;
            file_output_enabled[i] = true;
        }
    }
    
    log_config::log_config(std::string name) :
            name(name),
            file_flush_interval(0.5f),
            console_output_enabled(std::shared_ptr<bool[]>(new bool[5])),
            file_output_enabled(std::shared_ptr<bool[]>(new bool[5])) {
        for (int i = 0; i < 5; i++) {
            console_output_enabled[i] = true;
            file_output_enabled[i] = false;
        }
    }

}