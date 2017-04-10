/** Implementation of KBEST class */
#ifndef KBEST_H
#define KBEST_H

#include <vector>
#include <algorithm>

/** KBest class
 * This class uses STL, to find K best elements of a given vector
 * based on some comparator
 */
template <class T>
class KBest
{
private:
    /** The elements under consideration */
    std::vector<T> elems;

public:
    KBest(std::vector<T> elements) {
        elems = elements;
    }

    /** STL method to get K Best elements */
    template <typename Comparator>
    std::vector<T> getKBest(int k, Comparator& comparator) {
        std::sort(elems.begin(), elems.end(), comparator);
        std::vector<T> retval (elems.begin(), elems.begin()+k);
        return retval;
    }
};


#endif /* KBEST_H */
