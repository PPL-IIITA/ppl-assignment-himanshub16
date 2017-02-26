#ifndef COUPLE_H
#define COUPLE_H

#ifndef BOY_H
#include "../boys/boy.h"
#endif

#ifndef GIRL_H
#include "../girls/girl.h"
#endif

#ifndef GIFT_H
#include "../gifts/gift.h"
#endif

/* Couple class */
class Couple
{
private:
public:
    std::vector <Gift> gifts;   /* the vector of gifts for this couple */
    float happiness;            /* The happpiness of this couple */
    Boy boy;                    /* This is the boy */
    Girl girl;                  /* This is the girl */
    Couple(Boy b, Girl g);      /* Constructor */
    float findHappiness();      /* Find the happiness of this couple */
    float findCompatibility();  /* Find the compatibility of this couple */

    /* Form the gift basket (vector) for this couple from given gift list */
    void makeGiftBasket(std::vector<Gift> gifts);
};


/* Comparator to compare couples on basis of compatibility
 * For sorting in descending order
 */
bool compareOnCompatibility(Couple c1, Couple c2);

/* Comparator to compare couples on basis of happiness
 * For sorting in descending order
 */
bool compareOnHappiness(Couple c1, Couple c2);

#endif