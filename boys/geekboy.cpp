#include "geekboy.h"

float GeekBoy::getHappiness()
{
    float happiness = 0;
    if (!committed || !girlfriend || !gifts)
        return -1;

    happiness = this->girlfriend->intel;
    this->happiness = happiness;
    return happiness;
}
