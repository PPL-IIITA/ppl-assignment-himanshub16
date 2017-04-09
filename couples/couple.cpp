#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "couple.h"

bool compareOnHappiness (Couple c1, Couple c2)
{
    return (c1.findHappiness() > c2.findHappiness());
}

bool compareOnCompatibility(Couple c1, Couple c2)
{
    return (c1.findCompatibility() > c2.findCompatibility());
}

bool giftRemovalPred (Gift g)
{
    return (g.gifted || g.type != luxury);
}

Couple::Couple(Boy *b, Girl *g)
{
    boy = b;
    girl = g;
    boy->committed = true;
    boy->makeCouple(girl);
    girl->committed = true;
    girl->makeCouple(boy);
}

float Couple::findHappiness()
{
    float boyHapp = boy->getHappiness();
    float girlHapp = girl->getHappiness();
    return boyHapp + girlHapp;
}

void Couple::breakup()
{
    boy->committed = false;
    girl->committed = false;
    boy->makeCouple(NULL);
    girl->makeCouple(NULL);
}

void Couple::makeGiftBasket(std::vector<Gift> giftsList, Logger *logger)
{
    if (giftsList.empty()) return;

    gifts.clear();

    /* This is the maximum money to be spent.
       It is different for different types of boys.
    */
    int expenseLimit = 0;

    switch (boy->getNature()) {
    case miser:
    case geek:
        expenseLimit = girl->budget;
        std::sort (giftsList.begin(), giftsList.end(), compareOnPriceAsc);
        break;

    case generous:
        expenseLimit = boy->budget;
        std::sort (giftsList.begin(), giftsList.end(), compareOnPriceDesc);
        break;
    }

    /* start forming the basket */
    for (auto it = giftsList.begin(); it != giftsList.end() && expenseLimit > 0;  it++) {
        expenseLimit -= (*it).price;
        gifts.push_back(*it);
        (*it).gifted = true;
        logger->log("Gift", boy->name+" gifted "+(*it).name + " to "+ girl->name, true);
    }

    /* if no gifts have been given, then raise the budget of the boy */
    if (gifts.empty()) {
        boy->budget = expenseLimit = gifts[0].price;
        gifts.push_back(gifts[0]);
        logger->log("Budget", boy->name+ " raised his budget to "+ std::to_string(boy->budget), true);
        logger->log("Gift", boy->name+" gifted "+ gifts[0].name + " to "+ girl->name, true);
    }

    /* geek boys want to give a luxury gift */
    if (expenseLimit > 0 && boy->getNature() == geek) {
        /* find a luxury gift */
        std::remove_if(giftsList.begin(), giftsList.end(), giftRemovalPred);
        if (! giftsList.empty())
            gifts.push_back(giftsList[0]);
        logger->log("Luxury", boy->name+" gifted luxury gift "+ gifts[0].name + " to "+ girl->name, true);
    }

    boy->setGiftBasket(&gifts);
    girl->setGiftBasket(&gifts);
}

float Couple::findCompatibility()
{
    return (boy->budget - girl->budget) +
        abs(boy->attr   - girl->attr)   +
        abs(boy->intel  - girl->intel);
}
