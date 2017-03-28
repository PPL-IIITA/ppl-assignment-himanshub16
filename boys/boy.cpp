#include "boy.h"

bool compareOnIntelligence (Boy *b1, Boy *b2)
{
    return b1->intel > b2->intel;
}

bool compareOnAttractiveness (Boy *b1, Boy *b2)
{
    return b1->attr > b2->attr;
}

bool compareOnRichness (Boy *b1, Boy *b2)
{
    return b1->budget > b2->budget;
}

void Boy::makeCouple(Girl *girl)
{
    this->girlfriend = girl;
}

bool Boy::isCompatible(Girl *girl)
{
    return ( (girl->attr >= this->min_attr_req) &&
             (girl->budget <= this->budget) );
}

void Boy::setGiftBasket(std::vector<Gift> *gifts)
{
    this->gifts = gifts;
}

// Boy::Boy()
// {
//     this->committed  = false;
//     this->girlfriend = NULL;
//     this->gifts      = NULL;
//     this->happiness  = 0;
// }

// Boy::Boy(std::string name, int attr, int intel, int budget, int min_attr_req)
// {
//     this->name         = name;
//     this->intel        = intel;
//     this->attr         = attr;
//     this->budget       = budget;
//     this->min_attr_req = min_attr_req;
//     this->committed    = false;
//     this->happiness    = 0;
//     this->girlfriend   = NULL;
//     this->gifts        = NULL;
// }
