#include "generousboy.h"

GenerousBoy::GenerousBoy(std::string name, int attr, int intel, int budget, int min_attr_req)
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
float GenerousBoy::getHappiness()
{
    float happiness = 0;
    if (!committed || !girlfriend || !gifts)
        return -1;

    happiness = this->girlfriend->getHappiness();
    this->happiness = happiness;
    return happiness;
}
