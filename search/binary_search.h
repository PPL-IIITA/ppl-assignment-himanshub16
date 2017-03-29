#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "search.h"

class BinarySearch : public Search {
private:
    Boy* binarySearch (std::vector<Boy*> boys, int start, int end, std::string name);
public:
    BinarySearch(std::vector<Boy*> boylist);
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* BINARY_SEARCH_H */
