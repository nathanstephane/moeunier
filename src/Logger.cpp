#include "Logger.hpp"
#include <iostream>
#include <ctime>
#include <chrono>

//use spdlog

std::vector<LogEntry> Logger::messages;

 std::string currentDateTime()
 {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string output(20,'\0');
    std::strftime(&output[0],output.size(), "%d-%b-%Y %H:%M:%S", std::localtime(&now));
    return output;
 }
void Logger::Log(const std::string& message)
{
    LogEntry newLogEntry;
    newLogEntry.type = LOG_INFO;
    newLogEntry.message = "LOG: ["+currentDateTime()+"]: "+message;
    std::cout << "\x1b[32m" << newLogEntry.message<< "\33[0m" << std::endl;
    messages.push_back(newLogEntry);
}

void Logger::Err(const std::string& message)
{
    LogEntry newLogEntry;
    newLogEntry.type = LOG_INFO;
    newLogEntry.message = "ERR: ["+currentDateTime()+"]: "+message;
    std::cout << "\x1B[91m" << newLogEntry.message << "\33[0m" << std::endl;
    messages.push_back(newLogEntry);

}