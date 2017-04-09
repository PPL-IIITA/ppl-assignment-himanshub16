#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

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

void Couple::makeGiftBasket2(std::vector<Gift> giftsList, Logger *logger)
{
    if (giftsList.empty()) return;

    gifts.clear();

    int expenseLimit = boy->budget;
    /* Here the boy has to gift one gift of each type,
     * even if it surpasses his budget
     */
    std::vector<Gift> essentialGifts (giftsList.size());
    std::vector<Gift> luxuryGifts    (giftsList.size());
    std::vector<Gift> utilityGifts   (giftsList.size());

    auto it = std::copy_if (giftsList.begin(), giftsList.end(), essentialGifts.begin(), [](Gift g) { return (g.type != luxury)    && (g.type != utility);   });
    essentialGifts.resize(std::distance(essentialGifts.begin(), it)); // resize to shrink container space
         it = std::copy_if (giftsList.begin(), giftsList.end(), luxuryGifts.begin(),    [](Gift g) { return (g.type != essential) && (g.type != utility);   });
    luxuryGifts.resize(std::distance(luxuryGifts.begin(), it)); // resize to shrink container space
         it = std::copy_if (giftsList.begin(), giftsList.end(), utilityGifts.begin(),   [](Gift g) { return (g.type != luxury)    && (g.type != essential); });
    utilityGifts.resize(std::distance(utilityGifts.begin(), it)); // resize to shrink container space

    if (essentialGifts.size() == 1 || luxuryGifts.size() == 1 || utilityGifts.size() == 1) {
        logger->log("critical", "There is one gift possible for each type", true);
    }

    /* gift one gift of each type */
    gifts.push_back(essentialGifts[0]); gifts.push_back(luxuryGifts[0]); gifts.push_back(utilityGifts[0]);
    logger->log("Gift", boy->name+" has money of value "+std::to_string(expenseLimit), true);
    logger->log("Gift", boy->name+" gifted "+ essentialGifts[0].name + " & " + luxuryGifts[0].name + " & " + utilityGifts[0].name + " to "+ girl->name, true);
    for (auto g : gifts)
        expenseLimit -= g.price;

    logger->log("Gift", boy->name+" is left with "+std::to_string(expenseLimit), true);

    /* This gifting policy gifts essential gifts first, utitliy gifts next, and luxury gifts last */
    int ess_pos = 1, lux_pos = 1, uti_pos = 1;
    int ess_last = essentialGifts.size(), lux_last = luxuryGifts.size(), uti_last = utilityGifts.size();
    while (expenseLimit > 0) {
        if (ess_pos < ess_last) {
            gifts.push_back(essentialGifts[ess_pos]);
            expenseLimit -= essentialGifts[ess_pos].price;
            logger->log("Gift", boy->name+" gifted "+ essentialGifts[ess_pos].name + " to "+ girl->name, true);
            ess_pos++;
            continue;
        } else if (lux_pos < lux_last) {
            gifts.push_back(luxuryGifts[lux_pos]);
            expenseLimit -= luxuryGifts[lux_pos].price;
            logger->log("Gift", boy->name+" gifted "+ luxuryGifts[lux_pos].name + " to "+ girl->name, true);
            lux_pos++;
            continue;
        } else if (uti_pos < uti_last) {
            gifts.push_back(utilityGifts[uti_pos]);
            expenseLimit -= utilityGifts[uti_pos].price;
            logger->log("Gift", boy->name+" gifted " + utilityGifts[uti_pos].name + " to "+ girl->name, true);
            uti_pos++;
            continue;
        }
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
