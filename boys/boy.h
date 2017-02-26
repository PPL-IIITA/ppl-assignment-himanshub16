#ifndef BOY_H
#define BOY_H

#include "boy_type.h"
#include "../girls/girl.h"
#include "../gifts/gift.h"

#include <iostream>
#include <vector>

/* forward declaration */
class Girl;
class Gift;

class Boy
{
private:
    std::vector<Gift> gifts;
public:
    std::string name;
    int attr;
    int intel;
    int budget;
    int min_attr_req;
    float happiness;
    BoyNature nature;
    Girl *girlfriend;

    bool committed;

    Boy();
    Boy(std::string name, BoyNature type, int attr, int intel, int budget, int min_attr_req);

    void makeCouple(Girl *girl);
    void setGiftBasket(std::vector<Gift> gifts);
    bool isCompatible(Girl girl);
    float getHappiness();
};


bool compareOnAttractiveness (Boy b1, Boy b2);
bool compareOnIntelligence   (Boy b1, Boy b2);
bool compareOnRichness       (Boy b1, Boy b2);


#endif
