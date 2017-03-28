/* Some utilities for couple operations
 */

#include "../couples/couple.h"
#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include <algorithm>

#include "logger/logger.h"

/** Form couples from given list of boys and girls \n
 * Returns the vector of couples formed
 */
std::vector<Couple> makeCouples (std::vector<Boy*> boys,
                                 std::vector<Girl*> girls, Logger *logger)
{
    std::vector<Couple> couples;

    int i, j;
    for (i = 0; i < (int)girls.size(); i++) {
        if (girls[i]->committed) continue;

        /* Sort the boys as required */
        switch (girls[i]->boy_type) {
        case attractive:
            std::sort(boys.begin(), boys.end(), compareOnAttractiveness);
            break;
        case rich:
            std::sort(boys.begin(), boys.end(), compareOnRichness);
            break;
        case intelligent:
            std::sort(boys.begin(), boys.end(), compareOnIntelligence);
            break;
        }

        /* Find an appropriate boy */
        for (j = 0; j < (int)boys.size(); j++) {
            if (boys[j]->committed) continue;
            logger->log("Match", "Checking compatibility of "+boys[j]->name+" and "+girls[i]->name, false);
            if (boys[j]->isCompatible( girls[i] ) &&
                girls[i]->isCompatible( boys[j] ) ) {

                couples.push_back( Couple((boys)[j], girls[i]) );
                boys[j]->committed = true;
                girls[i]->committed = true;
                logger->log("Committed", boys[j]->name+" and "+girls[i]->name + " committed", false);
                break;
            }
        }
    }

    return couples;
}

/** Form couples from given list of boys and girls \n
 * Returns the vector of couples formed
 */
std::vector<Couple> makeCouplesAlternatively (std::vector<Boy*> boys,
                                 std::vector<Girl*> girls, Logger *logger)
{
    std::sort(girls.begin(), girls.end(), compareOnMaintenanceCost);
    std::sort(boys.begin(), boys.end(), compareOnAttractiveness);
    std::vector<Girl*> girlsCopy = girls;
    std::vector<Boy*>  boysCopy  = boys;
    std::vector<Couple> couples;

    int  i, j;
    for (i = 0; i < (int)girls.size(); i++) {
        if (girls[i]->committed) continue;
        std::sort(boysCopy.begin(), boysCopy.end(), compareOnAttractiveness);

        if (i % 2 == 0) {

            /* Sort the boys as required */
            switch (girls[i]->boy_type) {
            case attractive:
                std::sort(boysCopy.begin(), boysCopy.end(), compareOnAttractiveness);
                break;
            case rich:
                std::sort(boysCopy.begin(), boysCopy.end(), compareOnRichness);
                break;
            case intelligent:
                std::sort(boysCopy.begin(), boysCopy.end(), compareOnIntelligence);
                break;
            }

            /* Find an appropriate boy */
            for (j = 0; j < (int)boysCopy.size(); j++) {
                if (boysCopy[j]->committed) continue;
                logger->log("Match", "Checking compatibility of "+boysCopy[j]->name+" and "+girls[i]->name, false);
                if (boysCopy[j]->isCompatible( girls[i] ) &&
                    girls[i]->isCompatible( boys[j] ) ) {

                    couples.push_back( Couple((boysCopy)[j], girls[i]) );
                    boysCopy[j]->committed = true;
                    girls[i]->committed = true;
                    logger->log("Committed", boysCopy[j]->name+" and "+girls[i]->name + " committed", false);
                    break;
                }
            }

        } else {

            /* find first single boy */
            Boy *singleBoy = boys[0];
            for (int i = 0; i < (int)boys.size() && boys[i]->committed; i++)
                singleBoy = boys[i];

            /* Sort the girls with attractiveness */
            std::sort(girlsCopy.begin(), girlsCopy.end(), compareOnMaintenanceCost);

            for (auto it = girlsCopy.begin(); it != girlsCopy.end(); it++) {
                if ((*it)->committed) continue;
                couples.push_back( Couple(singleBoy, *it) );
                singleBoy->committed = true;
                (*it)->committed = true;
                logger->log("Committed", singleBoy->name+" and "+(*it)->name+" committed", false);
                break;
            }

        }
    }

    return couples;
}

/** Perform gifting for all these couples
 */
void performGifting (std::vector<Couple> *couples, std::vector<Gift> *giftlist, Logger *logger)
{
    for (auto it = couples->begin(); it != couples->end(); it++)
        it->makeGiftBasket(*giftlist, logger);
}

/** Find the list of k happiest couples from given list of couples \n
 * Returns the vector of happiest couples in descending order
 */
std::vector<Couple> getKHappiestCouples (std::vector<Couple> couples, int k)
{
    std::sort(couples.begin(), couples.end(), compareOnHappiness);
    std::vector<Couple> happyCouples (couples.begin(), couples.begin() + k);
    return happyCouples;
}

/** Find the list of k most compatible couples from given list of couples \n
 * Returns the vector of compatible couples in descending order
 */
std::vector<Couple> getKCompatibleCouples (std::vector<Couple> couples, int k)
{
    std::sort(couples.begin(), couples.end(), compareOnCompatibility);
    std::vector<Couple> happyCouples (couples.begin(), couples.begin() + k);
    return happyCouples;
}

/** Find the list of k unhappiest couples from given list of couples \n
 * Returns the vector of happiest couples in descending order
 */
std::vector<Couple> getKUnhappiestCouples (std::vector<Couple> couples, int k)
{
    std::sort(couples.rbegin(), couples.rend(), compareOnHappiness);
    std::vector<Couple> unhappyCouples (couples.begin(), couples.begin() + k);
    return unhappyCouples;
}


/** Perform breakup of given couples and assign the girls new boyfriends
 *  Solver for @question 4
 */
void performBreakupAndPairAgain (std::vector<Couple>happyCouples,
                                 std::vector<Couple> *couples,
                                 std::vector<Boy*> *boys,
                                 std::vector<Girl*> *girls,
                                 Logger *logger)
{
    std::vector<Couple> newCouples;
    newCouples.clear();
    for (std::vector<Couple>::iterator it = happyCouples.begin(); it != happyCouples.end(); it++) {
        auto girl = it->girl;
        auto boy = it->boy;
        it->breakup();
        /* Sort the boys as required */
        switch (girl->boy_type) {
        case attractive:
            std::sort(boys->begin(), boys->end(), compareOnAttractiveness);
            break;
        case rich:
            std::sort(boys->begin(), boys->end(), compareOnRichness);
            break;
        case intelligent:
            std::sort(boys->begin(), boys->end(), compareOnIntelligence);
            break;
        }

        /* Find an appropriate boy */
        for (int j = 0; j < (int)boys->size(); j++) {
            if ((*boys)[j]->committed ||
                (*boys)[j]->name == boy->name)
                continue;
            logger->log("Match", "Checking compatibility of "+(*boys)[j]->name+" and "+(*boys)[j]->name, false);
            if ((*boys)[j]->isCompatible( girl ) &&
                girl->isCompatible( (*boys)[j] ) ) {

                newCouples.push_back( Couple((*boys)[j], girl) );
                (*boys)[j]->committed = true;
                girl->committed = true;
                logger->log("Committed", (*boys)[j]->name+" and "+girl->name + " committed", false);
                break;
            }
        }
    }

    auto newCouplesItr = newCouples.begin();
    for (auto it = happyCouples.begin(); it != happyCouples.end(); it++) {
        for (auto jt = couples->begin(); jt != couples->end() && newCouplesItr != newCouples.end(); jt++) {
            if (it->boy->name == jt->boy->name) {
                couples->erase(jt);
                couples->push_back(*newCouplesItr);
                newCouplesItr++;
            }
        }
    }
}
