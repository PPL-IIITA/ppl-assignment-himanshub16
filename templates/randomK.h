/** Implementation of KRandom class */
#ifndef RANDOMK_H
#define RANDOMK_H

#include <vector>
#include <cstdlib>

/** This class returns a random choice from a given set */
template <class T>
class RandomK
{
private:
    /** The elements under consideration */
    std::vector<T> elems;

public:
    RandomK(std::vector<T> elements) {
        elems = elements;
    }

    /** Returns a random choice of element */
    T getRandomElem() {
        return elems [ rand() % elems.size() ];
    }
};


#endif /* RANDOMK_H */
