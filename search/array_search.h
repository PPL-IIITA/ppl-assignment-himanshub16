#ifndef ARRAY_SEARCH_H
#define ARRAY_SEARCH_H

#include "search.h"

class ArraySearch : public Search {
private:
    Boy* linearSearch (std::vector<Boy*> boyslist, std::string name);
public:
    ArraySearch(std::vector<Boy*> boylist);
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* ARRAY_SEARCH_H */
