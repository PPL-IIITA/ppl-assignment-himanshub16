#ifndef GEEKBOY_H
#define GEEKBOY_H

#include "boy.h"

class GeekBoy : public Boy {
private:
    static const BoyNature nature = geek;  /*!< Nature of boy */

public:
    GeekBoy(std::string name, int attr, int intel, int budget, int min_attr_req);
    float getHappiness() override;
    BoyNature getNature() override;
};

#endif /* GEEKBOY_H */
