/** q6 : perform breakup T times a month
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
    int t = T;
    if (argc >= 2)
        t = atoi(argv[1]);
    Logger logger(LOG_FILE);

    std::vector<Boy*>  boys  = readAllBoys(BOY_FILE);
    std::vector<Girl*> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift> gifts = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 6", true);
    logger.log("boys", std::to_string(boys.size()) + " record read", true);
    logger.log("girls", std::to_string(girls.size()) + " record read", true);
    logger.log("gifts", std::to_string(gifts.size()) + " record read", true);

    std::vector<Couple> couples = makeCouples(boys, girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed", true);

    logger.info("Couples list", true);
    for (int i = 0; i < (int)couples.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   couples[i].boy->name+" and "+couples[i].girl->name, true);

    for (int i = 0; i < t; i++) {
        logger.info("Performing breakup for t = "+std::to_string(i+1), true);
        performGifting(&couples, &gifts, &logger);
        std::vector<Couple> unhappyOnes = getCouplesWithHappinessLessThan(couples, t);
        performBreakupOnHappinessAndPairAgain(unhappyOnes, &couples, &boys, &girls, t, &logger);
        logger.info("couples with happiness less than "+std::to_string(t), true);
        for (int i = 0; i < (int)unhappyOnes.size(); i++)
            logger.log("couple"+std::to_string(i+1),
                       unhappyOnes[i].boy->name+" and "+unhappyOnes[i].girl->name, true);
    }

    return 0;
}
