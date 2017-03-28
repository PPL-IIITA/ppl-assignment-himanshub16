#ifndef GENEROUSBOY_H
#define GENEROUSBOY_H

#include "boy.h"

class GenerousBoy : public Boy {
private:
    static const BoyNature nature = generous;  /*!< Nature of boy */

public:
    /** Parametrized constructor */
    GenerousBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    /** Calculate happiness of the boy */
    float getHappiness() override;
    BoyNature getNature() override;
};

#endif /* GENEROUSBOY_H */
