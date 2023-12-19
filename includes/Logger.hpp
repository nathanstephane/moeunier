#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <vector>

enum logType {
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
};

struct LogEntry {
    logType type;
    std::string message;
};

class Logger{
public:
    static std::vector<LogEntry> messages; //everything declared as static needs to be defined in the cpp file.
    static void Log(const std::string& message);
    static void Err(const std::string& message);
};
#endif