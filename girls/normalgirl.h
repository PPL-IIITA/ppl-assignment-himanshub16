#ifndef NORMALGIRL_H
#define NORMALGIRL_H

#include "girl.h"

class NormalGirl : public Girl {
private:
    static const GirlNature nature = normal;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    NormalGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    float getHappiness();
};

#endif /* NORMALGIRL_H */
