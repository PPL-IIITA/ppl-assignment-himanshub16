/* Some utilities for couple operations
 */

#include "../couples/couple.h"
#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include <algorithm>

#include "logger/logger.h"

/** Form couples from given list of boys and girls \n
 * Returns the vector of couples formed
 */
std::vector<Couple> makeCouples (std::vector<Boy*> boys,
                                 std::vector<Girl*> girls, Logger *logger)
{
    std::vector<Couple> couples;

    int i, j;
    for (i = 0; i < (int)girls.size(); i++) {
        if (girls[i]->committed) continue;

        /* Sort the boys as required */
        switch (girls[i]->boy_type) {
        case attractive:
            std::sort(boys.begin(), boys.end(), compareOnAttractiveness);
            break;
        case rich:
            std::sort(boys.begin(), boys.end(), compareOnRichness);
            break;
        case intelligent:
            std::sort(boys.begin(), boys.end(), compareOnIntelligence);
            break;
        }

        /* Find an appropriate boy */
        for (j = 0; j < (int)boys.size(); j++) {
            if (boys[j]->committed) continue;
            logger->log("Match", "Checking compatibility of "+boys[j]->name+" and "+girls[i]->name, false);
            if (boys[j]->isCompatible( girls[i] ) &&
                girls[i]->isCompatible( boys[j] ) ) {

                couples.push_back( Couple((boys)[j], girls[i]) );
                boys[j]->committed = true;
                girls[i]->committed = true;
                logger->log("Committed", boys[j]->name+" and "+girls[i]->name + " committed", false);
                break;
            }
        }
    }

    return couples;
}

/** Find the list of k happiest couples from given list of couples \n
 * Returns the vector of happiest couples in descending order
 */
std::vector<Couple> getKHappiestCouples (std::vector<Couple> couples, int k)
{
    std::sort(couples.begin(), couples.end(), compareOnHappiness);
    std::vector<Couple> happyCouples (couples.begin(), couples.begin() + k);
    return happyCouples;
}

/** Find the list of k most compatible couples from given list of couples \n
 * Returns the vector of compatible couples in descending order
 */
std::vector<Couple> getKCompatibleCouples (std::vector<Couple> couples, int k)
{
    std::sort(couples.begin(), couples.end(), compareOnCompatibility);
    std::vector<Couple> happyCouples (couples.begin(), couples.begin() + k);
    return happyCouples;
}
