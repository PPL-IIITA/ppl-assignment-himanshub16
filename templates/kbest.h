#ifndef KBEST_H
#define KBEST_H

#include <vector>
#include <algorithm>

template <class T>
class KBest
{
private:
    std::vector<T> elems;

public:
    KBest(std::vector<T> elements) {
        elems = elements;
    }

    template <typename Comparator>
    std::vector<T> getKBest(int k, Comparator& comparator) {
        std::sort(elems.begin(), elems.end(), comparator);
        std::vector<T> retval (elems.begin(), elems.begin()+k);
        return retval;
    }
};


#endif /* KBEST_H */
