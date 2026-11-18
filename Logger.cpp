/*
This file contains the logger implementation
*/

#include "Logger.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace
{
    const char* toString(LogLevel level)
    {
        switch(level)
        {
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::WARNING:
                return "WARNING";
            case LogLevel::ERROR:
                return "ERROR";
        }
        return "UNKNOWN";
    }

    std::string currentTimestamp()
    {
        const auto now = std::chrono::system_clock::now();
        const std::time_t time = std::chrono::system_clock::to_time_t(now);

        std::tm localTime{};

        #ifdef _WIN32
            localtime_s(&localTime, &time);
        #else
            localtime_r(&time, &localTime);
        #endif

        std::ostringstream output;
        output << std::put_time(
            &localTime, "%Y-%m-%d %H:%M:%S"
        );

        return output.str();
    }
}

Logger::Logger(LogLevel level)
    : minimumLevel(level)
{
}

void Logger::setLogLevel(LogLevel level)
{
    minimumLevel = level;
}

void Logger::log(
    LogLevel level,
    const std::string& message)
{
    if(level < minimumLevel)
    {
        return;
    }
    std::cout<< currentTimestamp()
    <<" ["<<toString(level) <<"] "
    <<message <<'\n';
}

void Logger::debug(const std::string& message)
{
    log(LogLevel::DEBUG, message);
}

void Logger::info(const std::string& message)
{
    log(LogLevel::INFO, message);
}

void Logger::warning(const std::string& message)
{
    log(LogLevel::WARNING, message);
}

void Logger::error(const std::string& message)
{
    log(LogLevel::ERROR, message);
}