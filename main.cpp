#include "Logger.h"

int main()
{
    Logger logger1(LogLevel::DEBUG);
    Logger logger2(LogLevel::DEBUG);

    logger1.debug("Debug message from logger1");
    logger1.info("Information from logger1");

    logger2.debug("Debug message from logger2");
    logger2.info("Information from logger2");

    return 0;
}