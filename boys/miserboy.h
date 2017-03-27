#include "boy.h"

class MiserBoy : public Boy {
private:
    static const BoyNature nature = miser;  /*!< Nature of boy */

public:
    float getHappiness();
};
