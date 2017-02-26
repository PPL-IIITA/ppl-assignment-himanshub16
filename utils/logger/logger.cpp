#include <stdexcept>
#include <iostream>

#ifndef LOGGER_H
#include "logger.h"
#endif

Logger::Logger(char *filename)
{
    if (this->file.is_open())
        this->file.close();
    this->file.open(filename, std::ios::out | std::ios::app);
    if (this->file.fail()) {
        throw std::runtime_error ("Failed to open log file.\n");
    }
}

void Logger::log(const char *type, const char* msg)
{
    time(&rawtime);
    this->tmpstr = ctime(&rawtime);
    this->tmpstr[this->tmpstr.size() - 1] = '\0';
    this->file << this->tmpstr << " | " << type << " -- " << msg << std::endl;
}

Logger::~Logger()
{
    if (this->file.is_open())
        this->file.close();
    std::cout << "log ends";
}
