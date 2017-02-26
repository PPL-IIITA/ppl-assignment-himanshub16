#include <fstream>
#include <ctime>

#ifndef LOGGER_H
#define LOGGER_H

/* Class for logger */
class Logger
{
private:
    time_t rawtime;     /* Helper variable for time manipulation */
    std::string tmpstr; /* Helper variable for string manipulation */
    std::fstream file;  /* File stream to the log file */
public:
    /* Constructor with filename of log file as parameter */
    Logger (const std::string filename);

    /* Method to log single line statements
     * print = true prints it to stdout also
     */
    void info (const std::string msg, bool print=false);

    /* Method to log with type and detailed message
     * print = true prints it to stdout also
     */
    void log(const std::string type, const std::string msg, bool print=false);

    /* Destructor which closes file on invokation */
    ~Logger();
};

#endif
