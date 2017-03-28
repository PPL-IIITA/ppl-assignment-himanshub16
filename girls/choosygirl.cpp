#include "choosygirl.h"

#include <cmath>

ChoosyGirl::ChoosyGirl(std::string name, int attr, int intel, int budget, BoyType boy_type)
{
    this->name        = name;
    this->attr        = attr;
    this->intel       = intel;
    this->budget      = budget;
    this->boy_type    = boy_type;
    this->committed   = false;
    this->boyfriend   = NULL;
    this->gifts       = NULL;
    this->happiness   = 0;
}

float ChoosyGirl::getHappiness()
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
    }
    this->happiness = happiness;
    return this->happiness;
}

GirlNature ChoosyGirl::getNature()
{
    return nature;
}
