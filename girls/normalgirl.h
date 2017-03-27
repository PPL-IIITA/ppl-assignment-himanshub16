#include "girl.h"

class NormalGirl : public Girl {
private:
    static const GirlNature nature = normal;  /*!< Nature of girl */
public:
    float getHappiness();
};
