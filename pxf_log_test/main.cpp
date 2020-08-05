#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <time.h>
#include <thread>
#include <vector>

#include "pxf_log/pxf_log.hpp"
#include "pxf_log/severity.hpp"

using namespace std::string_literals;

float randF();

void main() {

    PXFLOG::pxf_log log;
    log.config.file_name = "./test.log";
    log.config.file_output_enabled[PXFLOG::entry_severity::DEBUG] = true;
    log.config.file_output_enabled[PXFLOG::entry_severity::INFO] = true;
    log.config.file_output_enabled[PXFLOG::entry_severity::WARNING] = true;
    log.config.file_output_enabled[PXFLOG::entry_severity::ERROR] = true;
    log.config.file_output_enabled[PXFLOG::entry_severity::FATAL] = true;
    log.config.name = "CAT_LOG"s;
    log.start(true);

    std::srand(time(NULL));
    std::vector<std::string> messages;
    messages.push_back("Cat stuff"s);
    messages.push_back("Hoogen"s);
    messages.push_back("Bloogen"s);
    messages.push_back("User did a thing"s);
    messages.push_back("Feed teh kitteh"s);


    for (int message_count = 5; message_count > 0; message_count--) {
        float second_delay = randF() * 3.0f;
        std::chrono::milliseconds milli_delay(int(second_delay * 1000));
        std::this_thread::sleep_for(milli_delay);
        std::string message = messages[rand() % messages.size()];
        PXFLOG::entry_severity severity = (PXFLOG::entry_severity)(rand() % 5);
        
        log.log(severity, message);
    }

    log.shutdown();
    std::cout << "---------Test Complete" << std::endl;
    int out;
    std::cin >> out;
}


float randF() {
    return float(rand()) / float(RAND_MAX);
}