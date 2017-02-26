#ifndef GIFT_H
#include "gift.h"
#endif


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


Gift::Gift()
{
    this->gifted = false;
}

Gift::Gift(std::string name, GiftType type, int price, int value)
{
    this->name   = name;
    this->type   = type;
    this->price  = price;
    this->value  = value;
    this->gifted = false;
}
