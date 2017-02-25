#include <fstream>
#include <ctime>

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    time_t rawtime;
    std::string tmpstr;
    std::fstream file;
public:
    Logger (char *filename);
    void log(char *type, char* msg);
    ~Logger();
};

#endif
