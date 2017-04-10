/** Header file for MiserBoy class */
#ifndef MISERBOY_H
#define MISERBOY_H

#include "boy.h"

/** MiserBoy class
 * Inherits Boy publicly
 */
class MiserBoy : public Boy {
private:
    static const BoyNature nature = miser;
public:
    /** Parametrized constructor */
    MiserBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    /** overriding getHappiness of base class */
    float getHappiness() override;
    /** overriding getNature of base class */
    BoyNature getNature() override;
};

#endif /* MISERBOY_H */
