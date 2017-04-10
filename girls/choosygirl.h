/** Header file for ChoosyGirl */
#ifndef CHOOSYGIRL_H
#define CHOOSYGIRL_H

#include "girl.h"

/** ChoosyGirl class
 * Inherits Girl publicly
 */
class ChoosyGirl : public Girl {
private:
    static const GirlNature nature = choosy;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    ChoosyGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    /** Override getHappiness of base class */
    float getHappiness() override;
    /** Override getNature of base class */
    GirlNature getNature() override;
};

#endif /* CHOOSYGIRL_H */
