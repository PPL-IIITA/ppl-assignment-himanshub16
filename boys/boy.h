/*!< Header file for boy class
 */

#ifndef BOY_H
#define BOY_H

#include "boy_type.h"
#include "../girls/girl.h"
#include "../gifts/gift.h"

#include <iostream>
#include <vector>

/** forward declaration */
class Girl;
class Gift;

/** Class for boy */
class Boy
{
private:
    std::vector<Gift> *gifts; /*!< Vector of gifts the boy has gifted */
public:
    std::string name;  /*!< Name of boy */
    int attr;          /*!< Attractiveness */
    int intel;         /*!< Intelligence */
    int budget;        /*!< Max money boy can spend */
    int min_attr_req;  /*!< Min attraction required from girl */
    float happiness;   /*!< Happiness of the boy */
    BoyNature nature;  /*!< Nature of boy */
    Girl *girlfriend;  /*!< Reference of his girlfriend */

    bool committed;    /*!< If he is committed */

    /** The default constructor */
    Boy();

    /** Parametrized constructor */
    Boy(std::string name, BoyNature type, int attr, int intel, int budget, int min_attr_req);

    /** Make 'her' 'his' girlfriend */
    void makeCouple(Girl *girl);

    /** Set vector of gifts for the boy */
    void setGiftBasket(std::vector<Gift> *gifts);

    /** Check if the girl is compatible with the boy */
    bool isCompatible(Girl girl);

    /** Calculate happiness of the boy */
    float getHappiness();
};


/** Comparator for sorting on the basis of attractiveness \n
 * For sorting in descending order
 */
bool compareOnAttractiveness (Boy b1, Boy b2);

/** Comparator for sorting on the basis of intelligence \n
 * For sorting in descending order
 */
bool compareOnIntelligence   (Boy b1, Boy b2);

/** Comparator for sorting on the basis of richness \n
 * For sorting in descending order
 */
bool compareOnRichness       (Boy b1, Boy b2);


#endif /* BOY_H */
