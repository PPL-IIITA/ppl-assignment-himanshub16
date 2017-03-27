#include "girl.h"

class DesperateGirl : public Girl {
private:
    static const GirlNature nature = desperate;  /*!< Nature of girl */
public:
    float getHappiness();
};
