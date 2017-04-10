#ifndef ARRAY_SEARCH_H
#define ARRAY_SEARCH_H

#include "search.h"

/** Class to perform linear search
 * Inherits class Search, public
 */
class ArraySearch : public Search {
private:
    /** Function which implements linear search */
    Boy* linearSearch (std::string name);
public:
    /** Constructor which initialises boylist */
    ArraySearch(std::vector<Boy*> boylist);
    /** overriden method to find girlfriends,
     * here, by linear search
     */
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* ARRAY_SEARCH_H */
