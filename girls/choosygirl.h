#ifndef CHOOSYGIRL_H
#define CHOOSYGIRL_H

#include "girl.h"

class ChoosyGirl : public Girl {
private:
    static const GirlNature nature = choosy;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    ChoosyGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    float getHappiness() override;
    GirlNature getNature() override;
};

#endif /* CHOOSYGIRL_H */
