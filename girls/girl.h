#ifndef GIRL_H
#define GIRL_H

#ifndef GIFT_H
#include "../gifts/gift.h"
#endif

#ifndef BOY_H
#include "../boys/boy.h"
#endif

#include <iostream>
#include <vector>

enum GirlNature {
    choosy,
    normal,
    desperate
};

class Girl
{
private:
    std::vector <Gift> *gifts;
public:
    bool isCommitted;
    std::string name;
    int attr;
    int intel;
    int budget;
    GirlNature nature;
    BoyNature boy_type;
    Boy *boyfriend;

    Girl(std::string name, int attr, int intel, int budget, GirlNature nature, BoyNature boy_type);
    void makeCouple(Boy *boy);
    void setGiftBasket(std::vector <Gift> *gifts);
    float getHappiness();
    bool isCompatible(Boy *boy);
};

#endif
