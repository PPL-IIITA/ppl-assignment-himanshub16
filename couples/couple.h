#ifndef COUPLE_H
#define COUPLE_H

#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include "../gifts/gift.h"
#include "../utils/logger/logger.h"

/** Couple class */
class Couple
{
private:
public:
    std::vector <Gift> gifts;   /*!< the vector of gifts for this couple */
    float happiness;            /*!< The happpiness of this couple */
    Boy *boy;                   /*!< This is the boy */
    Girl *girl;                 /*!< This is the girl */
    Couple(Boy *b, Girl *g);    /*!< Constructor */
    float findHappiness();      /*!< Find the happiness of this couple */
    float findCompatibility();  /*!< Find the compatibility of this couple */
    void breakup();             /*!< Breakup this couple */

    /** Form the gift basket (vector) for this couple from given gift list */
    void makeGiftBasket(std::vector<Gift> giftlist, Logger *logger);

    /** Form a gift basket such that it contains one gift of every type */
    void makeGiftBasket2(std::vector<Gift> giftlist, Logger *logger);
};


/** Comparator to compare couples on basis of compatibility \n
 * For sorting in descending order
 */
bool compareOnCompatibility(Couple c1, Couple c2);

/** Comparator to compare couples on basis of happiness \n
 * For sorting in descending order
 */
bool compareOnHappiness(Couple c1, Couple c2);


#endif
