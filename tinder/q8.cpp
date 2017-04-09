/* perform breakup of k unhappiest couples, and assign the
   girls who became single, another (new) boyfriend
 */

#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include "../gifts/gift.h"
#include "../couples/couple.h"
#include "../utils/read_data.h"
#include "../utils/couple_utils.h"
#include "../utils/logger/logger.h"

#include "../configs.h"

int main(int argc, char **argv)
{
    int k = K;
    if (argc >= 2)
        k = atoi(argv[1]);
    Logger logger(LOG_FILE);

    std::vector<Boy*>  boys  = readAllBoys(BOY_FILE);
    std::vector<Girl*> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift> gifts = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 4", true);
    logger.log("boys", std::to_string(boys.size()) + " record read", true);
    logger.log("girls", std::to_string(girls.size()) + " record read", true);
    logger.log("gifts", std::to_string(gifts.size()) + " record read", true);

    std::vector<Couple> couples = makeCouples(boys, girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed", true);

    logger.info("Couples list", true);
    for (int i = 0; i < (int)couples.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   couples[i].boy->name+" and "+couples[i].girl->name, true);

    switch(k) {
    case 2:
        performGifting2(&couples, &gifts, &logger);
        break;
    case 1:
    default:
        performGifting(&couples, &gifts, &logger);
        break;
    }
    return 0;
}
