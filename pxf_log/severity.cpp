#include "pxf_log/severity.hpp"

#include <string>
#include <vector>

std::vector<std::string> severity_name_map;

#define MAP_SEVERITY_NAME(x) severity_name_map.push_back(#x)

namespace PXFLOG {

    void init_severity_name_map() {
        MAP_SEVERITY_NAME(DEBUG);
        MAP_SEVERITY_NAME(INFO);
        MAP_SEVERITY_NAME(WARNING);
        MAP_SEVERITY_NAME(ERROR);
        MAP_SEVERITY_NAME(FATAL);
    }


    std::string severity_to_string(entry_severity severity) {
        if (!severity_name_map.size()) init_severity_name_map();
        return severity_name_map[severity];
    }
}