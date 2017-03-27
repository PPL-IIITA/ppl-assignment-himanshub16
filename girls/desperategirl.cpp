#include "desperategirl.h"

#include <cmath>
#define BASE 1.1

float DesperateGirl::getHappiness()
{
    float happiness = 0;
    if (!this->gifts)
        return -1;

    for (auto it = gifts->begin();
         it != gifts->end();
         it++) {

        happiness += pow(BASE, it->price);
    }
    this->happiness = happiness;
    return this->happiness;
}
