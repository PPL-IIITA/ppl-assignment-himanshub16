#include "boy.h"

bool compareOnIntelligence (Boy b1, Boy b2)
{
    return b1.intel > b2.intel;
}

bool compareOnAttractiveness (Boy b1, Boy b2)
{
    return b1.attr > b2.attr;
}

bool compareOnRichness (Boy b1, Boy b2)
{
    return b1.budget > b2.budget;
}

Boy::Boy()
{
    this->committed  = false;
    this->girlfriend = NULL;
    this->gifts      = NULL;
    this->happiness  = 0;
}

Boy::Boy(std::string name, BoyNature type, int attr, int intel, int budget, int min_attr_req)
{
    this->name         = name;
    this->nature       = type;
    this->intel        = intel;
    this->attr         = attr;
    this->budget       = budget;
    this->min_attr_req = min_attr_req;
    this->committed    = false;
    this->happiness    = 0;
    this->girlfriend   = NULL;
    this->gifts        = NULL;
}

float Boy::getHappiness()
{
    float happiness = 0;

    if (!this->committed ||
        !this->girlfriend ||
        !this->gifts)
        return -1;

    switch (this->nature) {
    case miser:
        happiness = this->budget;
        for (std::vector<Gift>::iterator it = this->gifts->begin();
             it != this->gifts->end();
             it++)
            happiness -= it->price;
        break;

    case generous:
        happiness = this->girlfriend->getHappiness();
        break;

    case geek:
        happiness = this->girlfriend->intel;
        break;

    default:
        return -1;
    }
    this->happiness = happiness;
    return happiness;
}

void Boy::makeCouple(Girl *girl)
{
    this->girlfriend = girl;
}

bool Boy::isCompatible(Girl girl)
{
    return ( (girl.attr >= this->min_attr_req) &&
             (girl.budget <= this->budget) );
}

void Boy::setGiftBasket(std::vector<Gift> *gifts)
{
    this->gifts = gifts;
}
