#ifndef SEARCH_H
#define SEARCH_H

#include "../boys/allboys.h"
#include "../utils/logger/logger.h"
#include <vector>
#include <iostream>


/** Abstract class which is used to implement various search algorithms */
class Search {
protected:
    /** Protected list of boys to search on */
    std::vector<Boy*> boyslist;

public:
    /* Abstract method to find girlfriends of given boys */
    virtual void findGirlfriends (std::vector<std::string> namelist, Logger *logger) = 0;
};


#endif /* SEARCH_H */
