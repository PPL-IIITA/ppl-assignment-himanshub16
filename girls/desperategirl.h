#ifndef DESPERATEGIRL_H
#define DESPERATEGIRL_H

#include "girl.h"

class DesperateGirl : public Girl {
private:
    static const GirlNature nature = desperate;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    DesperateGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    float getHappiness();
};

#endif /* DESPERATEGIRL_H */
