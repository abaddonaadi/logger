/*
This file contains the logger implementation
*/

#include "Logger.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace   //anonymous namespace
{
    /*
    We need this function because the enum class LogLevel return numerals for log levels.
    Thus, we need this function to convert log levels to actual string.
    We do not want logs to print like this "[3]Connection Failed" instead we want like "[ERROR]Connection Failed"

    const char* - Returns a pointer to a constant character string
    This function only converts the enum into readable text. It does not print anything.
    */
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

    /*
    Our objective is to generate something like: 2026-11-18 23:34:15
    */
    std::string currentTimestamp()
    {
        const auto now = std::chrono::system_clock::now();  //Gets the current time from system's clock.
        const std::time_t time = std::chrono::system_clock::to_time_t(now);  //Convert our current time to time_t value as CPP time formatting can use this traditional method

        std::tm localTime{}; //structure that stores calendar related info

        #ifdef _WIN32
            localtime_s(&localTime, &time); //This converts our time value to localTime structure
        #else
            localtime_r(&time, &localTime);
        #endif

        std::ostringstream output;  
        output << std::put_time(
            &localTime, "%Y-%m-%d %H:%M:%S"   //Formatting our date and time in desired way
        );

        return output.str();  //returning the stream
    }
}

/*
This is constructor implementation.
This initializes minimumLevel with the parameter passed during object creation.
*/
Logger::Logger(LogLevel level)
    : minimumLevel(level)
{
}

/* 
This fuunctions assgns minimumLevel with level.
You can modify the minimum level once the object is created.
*/
void Logger::setLogLevel(LogLevel level)
{
    minimumLevel = level;
}


/*
Actual logger functionality
*/
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


/*
Logger helpers : Convenience Function
You call logger.debug("Hello") -> it inturns calls log(LogLevel::DEBUG,"Hello")
*/
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