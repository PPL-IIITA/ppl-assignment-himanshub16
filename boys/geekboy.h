#include "boy.h"

class GeekBoy : public Boy {
private:
    static const BoyNature nature = geek;  /*!< Nature of boy */

public:
    float getHappiness();
};
