#include "binary_search.h"
#include <algorithm>


Boy* binarySearch (std::vector<Boy*> boys, int start, int end, std::string name)
{
    if (start == end)
        return NULL;
    int mid = (start + end)/2;
    if (boys[mid]->name == name)
        return boys[mid];
    Boy* leftResult = binarySearch(boys, start, mid-1, name);
    if (leftResult) return leftResult;
    Boy* rightResult = binarySearch(boys, mid+1, end, name);
    if (rightResult) return rightResult;

    return NULL;
}

BinarySearch::BinarySearch(std::vector<Boy*> boyslist)
{
    this->boyslist = boyslist;
}

void BinarySearch::findGirlfriends (std::vector<std::string> namelist, Logger *logger)
{
    auto lambda = [] (Boy* b1, Boy* b2) {
        return b1->name < b2->name;
    };
    std::sort(boyslist.begin(), boyslist.end(), lambda);
    for (auto name : namelist) {
        Boy *boy = binarySearch(this->boyslist, 0, this->boyslist.size(), name);
        if (boy) {
            logger->log("found", name+" boy found in list", true);
            if (boy->committed) {
        logger->log("q7:exists", name+" is committed with "+boy->girlfriend->name, true);
            } else {
                logger->log("q7:single", name+" is single", true);
            }
        }
    }
}
