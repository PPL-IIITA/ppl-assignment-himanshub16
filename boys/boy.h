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
    std::vector<Gift> *gifts;
public:
    std::string name;
    int attr;
    int intel;
    int budget;
    int min_attr_req;
    BoyNature nature;
    Girl *girlfriend;

    Boy();
    Boy(std::string name, BoyNature type, int attr, int intel, int budget, int min_attr_req);

    void makeCouple(Girl *girl);
    void setGiftBasket(std::vector<Gift> *gifts);
    bool isCompatible(Girl *girl);
    float getHappiness();
};

#endif
