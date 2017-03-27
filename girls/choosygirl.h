#include "girl.h"

class ChoosyGirl : public Girl {
private:
    static const GirlNature nature = choosy;  /*!< Nature of girl */
public:
    float getHappiness();
};
