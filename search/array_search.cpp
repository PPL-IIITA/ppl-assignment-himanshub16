#include "array_search.h"

Boy* ArraySearch::linearSearch(std::vector<Boy*> boyslist, std::string name)
{
    for (auto boy : boyslist) {
        if (boy->name == name)
            return boy;
    }
    return NULL;
}

ArraySearch::ArraySearch(std::vector<Boy*> boyslist)
{
    this->boyslist = boyslist;
}


void ArraySearch::findGirlfriends (std::vector<std::string> namelist, Logger *logger)
{
    for (auto name : namelist) {
        auto boy = linearSearch(boyslist, name);
        if (boy) {
            logger->log("found", name+" boy found in list", true);
            if (boy->committed) {
                logger->log("q7:exists", name+" is committed with "+boy->girlfriend->name, true);
            } else {
                logger->log("q7:single", name+" is single", true);
            }
        } else {
            logger->log("not found", name, true);
        }
    }
}
