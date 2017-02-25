#include "boy.h"

Boy::Boy()
{
}

Boy::Boy(std::string name, BoyNature type, int attr, int intel, int budget, int min_attr_req)
{
    this->name         = name;
    this->nature       = type;
    this->intel        = intel;
    this->attr         = attr;
    this->budget       = budget;
    this->min_attr_req = min_attr_req;
}

float Boy::getHappiness()
{
    float happiness;
    switch (this->nature) {
    case miser:
        happiness = this->budget;
        for (std::vector<Gift>::iterator it = gifts->begin();
             it != gifts->end();
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
    return happiness;
}

void Boy::makeCouple(Girl *girl)
{
    this->girlfriend = girl;
}

bool Boy::isCompatible(Girl *girl)
{
    if (girl->attr >= this->min_attr_req &&
        girl->budget <= this->budget)
        return true;
    return false;
}

void Boy::setGiftBasket(std::vector<Gift> *gifts)
{
    this->gifts = gifts;
}
