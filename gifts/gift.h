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


bool compareOnValue (Gift g1, Gift g2)
{
    return (g1.value > g2.value);
}

bool compareOnPriceAsc (Gift g1, Gift g2)
{
    return (g1.price < g2.value);
}

bool compareOnPriceDesc (Gift g1, Gift g2)
{
    return (g1.price > g2.price);
}

#endif
