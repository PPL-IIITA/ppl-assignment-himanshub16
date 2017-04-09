#ifndef RANDOMK_H
#define RANDOMK_H

#include <vector>
#include <cstdlib>

template <class T>
class RandomK
{
private:
    std::vector<T> elems;

public:
    RandomK(std::vector<T> elements) {
        elems = elements;
    }

    T getRandomElem() {
        return elems [ rand() % elems.size() ];
    }
};


#endif /* RANDOMK_H */
