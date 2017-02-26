#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "couple.h"

bool compareOnHappiness (Couple c1, Couple c2)
{
    return (c1.findHappiness() > c2.findHappiness());
}

bool compareOnCompatibility(Couple c1, Couple c2) {
    return (c1.findCompatibility() > c2.findCompatibility());
}

bool giftRemovalPred (Gift g)
{
    return (g.gifted || g.type != luxury);
}

Couple::Couple(Boy b, Girl g)
{
    this->boy = b;
    this->girl = g;
    this->boy.committed = true;
    this->girl.committed = true;
}

float Couple::findHappiness()
{
    float boyHapp = this->boy.getHappiness();
    float girlHapp = this->girl.getHappiness();
    return boyHapp + girlHapp;
}

void Couple::makeGiftBasket(std::vector<Gift> giftsList, Logger *logger)
{
    if (giftsList.empty()) return;

    this->gifts.clear();

    /* This is the maximum money to be spent.
       It is different for different types of boys.
     */
    int expenseLimit = 0;

    switch (this->boy.nature) {
    case miser:
    case geek:
        expenseLimit = this->girl.budget;
        std::sort (giftsList.begin(), giftsList.end(), compareOnPriceAsc);
        break;

    case generous:
        expenseLimit = this->boy.budget;
        std::sort (giftsList.begin(), giftsList.end(), compareOnPriceDesc);
        break;
    }

    /* start forming the basket */
    for (std::vector<Gift>::iterator it = giftsList.begin();
         it != giftsList.end() && expenseLimit > 0;
         it++) {
        expenseLimit -= (*it).price;
        this->gifts.push_back(*it);
        (*it).gifted = true;
        logger->log("Gift", this->boy.name+" gifted "+(*it).name + " to "+ this->girl.name, true);
    }

    /* if no gifts have been given, then raise the budget of the boy */
    if (gifts.empty()) {
        this->boy.budget = expenseLimit = gifts[0].price;
        this->gifts.push_back(gifts[0]);
        logger->log("Budget", this->boy.name+ " raised his budget to "+ std::to_string(this->boy.budget), true);
        logger->log("Gift", this->boy.name+" gifted "+ gifts[0].name + " to "+ this->girl.name, true);
    }

    /* geek boys want to give a luxury gift */
    if (expenseLimit > 0 && this->boy.nature == geek) {
        /* find a luxury gift */
        std::remove_if(giftsList.begin(), giftsList.end(), giftRemovalPred);
        if (! giftsList.empty())
            this->gifts.push_back(giftsList[0]);
        logger->log("Luxury", this->boy.name+" gifted luxury gift "+ gifts[0].name + " to "+ this->girl.name, true);
    }

    this->boy.setGiftBasket(&this->gifts);
    this->girl.setGiftBasket(&this->gifts);
}

float Couple::findCompatibility()
{
    return (this->boy.budget - this->girl.budget) +
        abs(this->boy.attr   - this->girl.attr)   +
        abs(this->boy.intel  - this->girl.intel);
}
