/** Header file for generous boy */
#ifndef GENEROUSBOY_H
#define GENEROUSBOY_H

#include "boy.h"

/** GenerousBoy class
 * Inherits Boy publicly
 */
class GenerousBoy : public Boy {
private:
    static const BoyNature nature = generous;  /*!< Nature of boy */

public:
    /** Parametrized constructor */
    GenerousBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    /** overriding getHappiness of base class */
    float getHappiness() override;
    /** overriding getNature of base class */
    BoyNature getNature() override;
};

#endif /* GENEROUSBOY_H */
