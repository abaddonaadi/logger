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
        LogLevel minimumLevel;    //Setting the minimum loglevel to be printed

    public:
        explicit Logger(LogLevel level = LogLevel::DEBUG);    /*Constructor with default value
                                                                What does explicit do? - It prevents unintended implicit conversion into Logger objects.
                                                                                         It is useful to safeguard constructor taht accepts one argument.*/

        void setLogLevel(LogLevel level);   //Function Prototype - Responsible to change minimum logging level

        void log(LogLevel level, const std::string& message);    // Logging Functionality - Parameters:- log severity, log message

        void debug(const std::string& message); //Convenience Function 
        void info(const std::string& message);  //Convenience Function
        void warning(const std::string& message);  //Convenience Function
        void error(const std::string& message);  //Convenience Function
};

#endif