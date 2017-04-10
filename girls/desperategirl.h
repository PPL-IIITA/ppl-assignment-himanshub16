/** Header file for desperate girl class */
#ifndef DESPERATEGIRL_H
#define DESPERATEGIRL_H

#include "girl.h"

/* DesperateGirl class
 * Inherits Girl publicly
 */
class DesperateGirl : public Girl {
private:
    static const GirlNature nature = desperate;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    DesperateGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    /** Override getHappiness of base class */
    float getHappiness() override;
    /** Override getNature of base class */
    GirlNature getNature() override;
};

#endif /* DESPERATEGIRL_H */
