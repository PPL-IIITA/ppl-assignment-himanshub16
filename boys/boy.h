#ifndef BOY_H
#define BOY_H

#ifndef GIRL_H
#include "../girls/girl.h"
#endif

#ifndef GIFT_H
#include "../gifts/gift.h"
#endif

#include <iostream>

enum BoyType {
    miser,
    generous,
    geek
};

class Boy
{
private:
    std::vector <Gift> *gifts;
public:
    std::string name;
    int attr;
    itn intel;
    int budget;
    int min_attr_req;
    BoyType type;
    Girl *girlfriend;
    Boy(std::string name, BoyType type, int attr, int intel, int budget, int min_attr_req);

    void makeCouple(Girl *girl);
    void setGiftBasket(std::vector <Gift> *gifts);
    bool isCompatible(Girl *girl);
    float getHappiness();
}

#endif
