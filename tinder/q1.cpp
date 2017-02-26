/* allocate boyfriends to all girls in same order as given in input
 */

#include "../boys/boy.h"
#include "../girls/girl.h"
#include "../gifts/gift.h"
#include "../couples/couple.h"
#include "../utils/read_data.h"
#include "../utils/couple_utils.h"
#include "../utils/logger/logger.h"

#include "configs.h"


int main(int argc, char **argv)
{
    Logger logger(LOG_FILE);

    std::vector<Boy>  boys  = readAllBoys(BOY_FILE);
    std::vector<Girl> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift> gifts = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 1", true);
    logger.log("boys", std::to_string(boys.size()) + " record read", true);
    logger.log("girls", std::to_string(girls.size()) + " record read", true);
    logger.log("gifts", std::to_string(gifts.size()) + " record read", true);

    std::vector<Couple> couples = makeCouples(&boys, &girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed", true);

    logger.info("Couples list", true);
    for (int i = 0; i < (int)couples.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   couples[i].boy.name+" and "+couples[i].girl.name, true);

    return 0;
}
