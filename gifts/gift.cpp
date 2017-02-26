#ifndef GIFT_H
#include "gift.h"
#endif

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
