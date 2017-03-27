#include "normalgirl.h"

#include <cmath>
#define BASE 1.1

float NormalGirl::getHappiness()
{
    float happiness = 0;
    if (!this->gifts)
        return -1;

    for (auto it = gifts->begin();
         it != gifts->end();
         it++) {
        happiness += it->price + it->value;
    }
    this->happiness = happiness;
    return this->happiness;
}
