#include "miserboy.h"

float MiserBoy::getHappiness()
{
    float happiness = 0;
    if (!committed || !girlfriend || !gifts)
        return -1;

    happiness = budget;
    for (auto it = gifts->begin(); it != gifts->end(); it++) {
        happiness -= it->price;
    }
    this->happiness = happiness;
    return happiness;
}
