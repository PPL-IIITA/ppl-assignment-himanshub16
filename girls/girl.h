#ifndef GIRL_H
#define GIRL_H

#include "girl_type.h"
#include "../boys/boy.h"
#include "../gifts/gift.h"

#include <iostream>
#include <vector>

/** forward declaration */
class Boy;
class Gift;

/** Class for girl
 * Abstract class
 */
class Girl
{
private:
    /* static const GirlNature nature;         /\*!< Nature of girl *\/ */
public:
    bool committed;            /*!< Whether she is committed */
    std::string name;          /*!< Name of the girl */
    int attr;                  /*!< Attractiveness of girl */
    int intel;                 /*!< Intelligence of girl */
    int budget;                /*!< Expenses of girl */
    float happiness;           /*!< Happiness of girl */
    BoyType boy_type;          /*!< Type of boy she is seeking */
    Boy *boyfriend;            /*!< Reference to her boyfriend */

    std::vector<Gift> *gifts;  /*!< The gifts girl has received */
    /* Girl(); /\*!< Default constructor *\/ */

    /* /\** Parametrized constructor *\/ */
    /* Girl(std::string name, int attr, int intel, int budget, BoyType boy_type); */

    /** Make 'him' 'her' boyfriend */
    void makeCouple(Boy *boy);

    /** Set giftbasket for the girl */
    void setGiftBasket(std::vector <Gift> *gifts);

    /** Find the happiness of the girl
     * Abstract method
     */
    virtual float getHappiness() = 0;

    /** Get nature of the girl
     * Abstract method
     */
    virtual GirlNature getNature() = 0;

    /** Check if the girl is compatible with the boy */
    bool isCompatible(Boy *boy);
};


/** Comparator to compare girls based on maintenance cost
 */
bool compareOnMaintenanceCost(Girl *g1, Girl *g2);

#endif /* GIRL_H */
