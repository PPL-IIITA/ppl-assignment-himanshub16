#include "boy.h"

class GenerousBoy : public Boy {
private:
    static const BoyNature nature = generous;  /*!< Nature of boy */

public:
    float getHappiness();
};
