#include "Logger.h"

int main()
{
    Logger logger1(LogLevel::DEBUG);  //logger1 object created of Logger class
    Logger logger2(LogLevel::DEBUG);  //logger2 object created of Logger class

    logger1.debug("Debug message from logger1");  
    logger1.info("Information from logger1");

    logger2.debug("Debug message from logger2");
    logger2.info("Information from logger2");

    logger1.setLogLevel(LogLevel::WARNING);

    logger1.info("This message should not appear");
    logger1.warning("This message should appear");

    return 0;
}