#include "hash_search.h"

void HashSearch::makeHashTable()
{
    for (auto boy : boyslist) {
        hashTable[boy->name] = boy;
    }
}

HashSearch::HashSearch(std::vector<Boy*> boyslist)
{
    this->boyslist = boyslist;
}

void HashSearch::findGirlfriends (std::vector<std::string> namelist, Logger *logger)
{
    makeHashTable();
    for (auto name : namelist) {
        auto searchResult = hashTable.find(name);
        if (searchResult != hashTable.end()) {
            Boy* boy = searchResult->second;
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
