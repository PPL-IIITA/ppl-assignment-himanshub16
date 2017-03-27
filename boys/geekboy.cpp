#include "geekboy.h"

GeekBoy::GeekBoy(std::string name, int attr, int intel, int budget, int min_attr_req)
{
    this->name         = name;
    this->intel        = intel;
    this->attr         = attr;
    this->budget       = budget;
    this->min_attr_req = min_attr_req;
    this->committed    = false;
    this->happiness    = 0;
    this->girlfriend   = NULL;
    this->gifts        = NULL;
}

float GeekBoy::getHappiness()
{
    float happiness = 0;
    if (!committed || !girlfriend || !gifts)
        return -1;

    happiness = this->girlfriend->intel;
    this->happiness = happiness;
    return happiness;
}
