#include "array_search.h"
#include <iostream>

Boy* ArraySearch::linearSearch(std::string name)
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
        logger->info("checking for "+name, true);
        Boy* boy = linearSearch(name);
        if (boy != NULL) {
            logger->log("found", boy->name+" boy found in list", true);
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
