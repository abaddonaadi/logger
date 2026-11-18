/*
This file declares the class and its public interface
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>

enum class LogLevel{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger
{
    private:
        LogLevel minimumLevel;

    public:
        explicit Logger(LogLevel level = LogLevel::DEBUG);

        void setLogLevel(LogLevel level);

        void log(LogLevel level, const std::string& message);

        void debug(const std::string& message);
        void info(const std::string& message);
        void warning(const std::string& message);
        void error(const std::string& message);
};

#endif