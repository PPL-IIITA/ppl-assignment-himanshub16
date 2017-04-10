/** Header for normalgirl class */
#ifndef NORMALGIRL_H
#define NORMALGIRL_H

#include "girl.h"

/* NormalGirl class
 * Inherits Girl publicly
 */
class NormalGirl : public Girl {
private:
    static const GirlNature nature = normal;  /*!< Nature of girl */
public:
    /** Parametrized constructor */
    NormalGirl(std::string name, int attr, int intel, int budget, BoyType boy_type);
    /** Override getHappiness of base class */
    float getHappiness() override;
    /** Override getNature of base class */
    GirlNature getNature() override;
};

#endif /* NORMALGIRL_H */
