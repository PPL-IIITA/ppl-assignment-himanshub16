#ifndef SEARCH_H
#define SEARCH_H

#include "../boys/allboys.h"
#include "../utils/logger/logger.h"
#include <vector>


class Search {
protected:
    std::vector<Boy*> boyslist;

public:
    virtual void findGirlfriends (std::vector<std::string> namelist, Logger *logger) = 0;
};


#endif /* SEARCH_H */
