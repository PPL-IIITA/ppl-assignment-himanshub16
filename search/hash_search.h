#ifndef HASH_SEARCH_H
#define HASH_SEARCH_H

#include "search.h"
#include <map>

/** Class to implement hash search,
 * Inherits Search public
 */
class HashSearch : public Search {
    /** Hashtable for lookups */
    std::map <std::string, Boy*> hashTable;
    /** Function which makes the hash table */
    void makeHashTable();
public:
    HashSearch(std::vector<Boy*> boylist);
    /** overriden method to find girlfriends,
     * here, by hash search
     */
    void findGirlfriends (std::vector<std::string> namelist, Logger *logger) override;
};


#endif /* HASH_SEARCH_H */
