#ifndef GIFT_H
#define GIFT_H

#include <iostream>

/** enum for the types of gifts */
enum GiftType {
    essential,
    luxury,
    utility
};

/** Class for Gifts */
class Gift
{
public:
    std::string name; /*!< Name of the gift */
    GiftType type;    /*!< Type of the gift */
    int price;        /*!< The price of the gift */
    int value;        /*!< The value of the gift */
    bool gifted;      /*!< Whether the gift has been gifted
                       * required for couple operations
                       */

    Gift();           /*!< The default constructor */

    /*!< Parametrized constructor */
    Gift(std::string name, GiftType type, int price, int value);
};


/** Comparator to compare Gifts on basis of their value \n
 * For sorting in descending order
 */
bool compareOnValue (Gift g1, Gift g2);

/** Comparator to compare Gifts on basis of their price \n
 * For sorting in ascending order
 */
bool compareOnPriceAsc (Gift g1, Gift g2);

/** Comparator to compare Gifts on basis of their price \n
 * For sorting in descending order
 */
bool compareOnPriceDesc (Gift g1, Gift g2);

#endif
