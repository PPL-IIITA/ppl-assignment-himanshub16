#ifndef GIRL_H
#define GIRL_H

#include "girl_type.h"
#include "../boys/boy.h"
#include "../gifts/gift.h"

#include <iostream>
#include <vector>

/* forward declaration */
class Boy;
class Gift;

class Girl
{
private:
    std::vector<Gift> *gifts;
public:
    bool isCommitted;
    std::string name;
    int attr;
    int intel;
    int budget;
    GirlNature nature;
    BoyNature boy_type;
    Boy *boyfriend;

    Girl();
    Girl(std::string name, int attr, int intel, int budget, GirlNature nature, BoyNature boy_type);
    void makeCouple(Boy *boy);
    void setGiftBasket(std::vector <Gift> *gifts);
    float getHappiness();
    bool isCompatible(Boy *boy);
};

#endif
