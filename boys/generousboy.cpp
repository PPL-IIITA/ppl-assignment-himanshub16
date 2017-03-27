#include "generousboy.h"

float GenerousBoy::getHappiness()
{
    float happiness = 0;
    if (!committed || !girlfriend || !gifts)
        return -1;

    happiness = this->girlfriend->getHappiness();
    this->happiness = happiness;
    return happiness;
}
