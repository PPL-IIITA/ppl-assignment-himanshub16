#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "search.h"

/** Class to implement binarySearch
 * Inerhits Search public
 */
class BinarySearch : public Search {
private:
    /* Function which implements binary Search */
    Boy* binarySearch (std::vector<Boy*> boys, int start, int end, std::string name);
public:
    /* constructor which inititalises boylist */
    BinarySearch(std::vector<Boy*> boylist);
    /** overriden method to find girlfriends,
     * here, by binary search
     */
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* BINARY_SEARCH_H */
