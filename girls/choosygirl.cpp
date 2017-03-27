#include "choosygirl.h"

#include <cmath>
#define BASE 1.1

float Girl::getHappiness()
{
    float happiness = 0;
    if (!this->gifts)
        return -1;

    for (std::vector<Gift> ::iterator it = gifts->begin();
         it != gifts->end();
         it++) {

        happiness += log10(it->price);
        if (it->type == luxury)
            happiness += it->value*2;
        this->happiness = happiness;
        return this->happiness;
    }
}
