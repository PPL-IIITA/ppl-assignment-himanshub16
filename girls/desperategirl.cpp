#include "desperategirl.h"

#include <cmath>
#define BASE 1.1

DesperateGirl::DesperateGirl(std::string name, int attr, int intel, int budget, BoyType boy_type)
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

float DesperateGirl::getHappiness()
{
    float happiness = 0;
    if (!this->gifts)
        return -1;

    for (auto it = gifts->begin( );
         it != gifts->end();
         it++) {

        happiness += pow(BASE, it->price);
    }
    this->happiness = happiness;
    return this->happiness;
}
