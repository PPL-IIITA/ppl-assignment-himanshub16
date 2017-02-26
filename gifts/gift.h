#ifndef GIFT_H
#define GIFT_H

#include <iostream>

enum GiftType {
    essential,
    luxury,
    utility
};

class Gift
{
public:
    std::string name;
    GiftType type;
    int price;
    int value;
    bool gifted;

    Gift();
    Gift(std::string name, GiftType type, int price, int value);
};


bool compareOnValue (Gift g1, Gift g2);
bool compareOnPriceAsc (Gift g1, Gift g2);
bool compareOnPriceDesc (Gift g1, Gift g2);

#endif
