#include "girl.h"

#include <cmath>

Girl::Girl()
{

}

Girl::Girl(std::string name, int attr, int intel, int budget, GirlNature nature, BoyNature boy_type)
{
    this->name        = name;
    this->attr        = attr;
    this->intel       = intel;
    this->budget      = budget;
    this->nature      = nature;
    this->boy_type    = boy_type;
    this->isCommitted = false;
}

float Girl::getHappiness()
{
    float happiness = 0;
    for (std::vector<Gift> ::iterator it = gifts->begin();
         it != gifts->end();
         it++) {

        switch (this->nature) {
        case choosy:
            happiness += log(it->price);
            if (it->type == luxury)
                happiness += it->value*2;
            break;

        case normal:
            happiness += it->price + it->value;
            break;

        case desperate:
            happiness += exp(it->price);
            break;

        default:
            return -1;
        }
    }
    return happiness;
}

bool Girl::isCompatible(Boy *boy)
{
    if (boy->budget >= this->budget &&
        boy->type == this->boy_type)
        return true;
    return false;
}

void Girl::makeCouple(Boy *boy)
{
    this->boyfriend = boy;
}

void Girl::setGiftBasket(std::vector<Gift> *gifts)
{
    this->gifts = gifts;
}
