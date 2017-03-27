#include "girl.h"

#include <cmath>
#define BASE 1.1

Girl::Girl()
{
    this->committed = false;
    this->boyfriend = NULL;
    this->gifts     = NULL;
    this->happiness = 0;
}

Girl::Girl(std::string name, int attr, int intel, int budget, BoyType boy_type)
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

float Girl::getHappiness()
{
    float happiness = 0;
    if (!this->gifts)
        return -1;

    for (std::vector<Gift> ::iterator it = gifts->begin();
         it != gifts->end();
         it++) {

        switch (this->nature) {
        case choosy:
            happiness += log10(it->price);
            if (it->type == luxury)
                happiness += it->value*2;
            break;

        case normal:
            happiness += it->price + it->value;
            break;

        case desperate:
            happiness += pow(BASE, it->price);
            break;

        default:
            return -1;
        }
    }
    this->happiness = happiness;
    return this->happiness;
}

bool Girl::isCompatible(Boy boy)
{
    return (boy.budget >= this->budget);
}

void Girl::makeCouple(Boy *boy)
{
    this->boyfriend = boy;
}

void Girl::setGiftBasket(std::vector<Gift> *gifts)
{
    this->gifts = gifts;
}
