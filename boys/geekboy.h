/** Header file for GeekBoy */
#ifndef GEEKBOY_H
#define GEEKBOY_H

#include "boy.h"

/** GeekBoy class
 * Ineherits Boy publicly
 */
class GeekBoy : public Boy {
private:
    static const BoyNature nature = geek;  /*!< Nature of boy */

public:
    GeekBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    /** overriding getHappiness of base class */
    float getHappiness() override;
    /** overriding getNature of base class */
    BoyNature getNature() override;
};

#endif /* GEEKBOY_H */
