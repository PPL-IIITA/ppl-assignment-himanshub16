#ifndef MISERBOY_H
#define MISERBOY_H

#include "boy.h"

class MiserBoy : public Boy {
private:
    static const BoyNature nature = miser;
public:
    /** Parametrized constructor */
    MiserBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    /** Calculate happiness of the boy */
    float getHappiness() override;
};

#endif /* MISERBOY_H */
