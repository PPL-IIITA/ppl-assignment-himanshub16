#include <stdexcept>
#include <iostream>

#ifndef LOGGER_H
#include "logger.h"
#endif

Logger::Logger(const std::string filename)
{
    if (this->file.is_open())
        this->file.close();
    this->file.open(filename.c_str(), std::ios::out | std::ios::app);
    if (this->file.fail()) {
        throw std::runtime_error ("Failed to open log file.\n");
    }
}

void Logger::info(const std::string msg, bool print)
{
    this->file << msg << std::endl;

    if (print) {
        std::cout << msg << std::endl;
    }
}

void Logger::log(const std::string type, const std::string msg, bool print)
{
    time(&rawtime);
    this->tmpstr = ctime(&rawtime);
    this->tmpstr[this->tmpstr.size() - 1] = '\0';
    this->file << this->tmpstr << " | ";
    this->file.width(10);
    this->file << std::left << type << " -- ";
    this->file.width(0);
    this->file << msg << std::endl;

    if (print) {
        std::cout << this->tmpstr << " | ";
        std::cout << type << " -- " << msg << std::endl;
    }
}

Logger::~Logger()
{
    if (this->file.is_open())
        this->file.close();
}
