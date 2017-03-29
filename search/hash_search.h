#ifndef HASH_SEARCH_H
#define HASH_SEARCH_H

#include "search.h"
#include <map>

class HashSearch : public Search {
    std::map <std::string, Boy*> hashTable;
    void makeHashTable();
public:
    HashSearch(std::vector<Boy*> boylist);
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* HASH_SEARCH_H */
