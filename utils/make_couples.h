#include <iostream>
#include <vector>
#include <algorithm>

#include "../couples/couple.h"
#include "logger/logger.h"

std::vector<Couple> makeCouples (std::vector<Boy> *boys,
                                 std::vector<Girl> *girls)
{
    std::vector<Couple> couples;
    couples.erase();
    int i, j;
    for (i = 0; i < (int)(*girls).size(); i++) {
        if ((*girls)[i].committed) continue;

        /* find an appropriate boy */
        switch ((*girls)[i].boy_type) {
        case attractive:
            std::sort((*boys).begin(), (*boys).end(), compareOnAttractiveness);
            break;
        case rich:
            std::sort((*boys).begin(), (*boys).end(), compareOnRichness);
            break;
        case intelligent:
            std::sort((*boys).begin(), (*boys).end(), compareOnIntelligence);
            break;
        }
        for (j = 0; j < (int)(*boys).size(); j++) {
            if ((*boys)[j].committed) continue;
            if ((*boys)[j].isCompatible((*girls)[i]) &&
                (*girls)[i].isCompatible((*boys)[j])) {

                    couples.push_back(Couple(&(*boys)[j], &(*girls)[i]));
                    break;
                }
        }
    }

    return couples;
}
