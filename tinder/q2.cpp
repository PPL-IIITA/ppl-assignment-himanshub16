
/* allocate boyfriends to all girls in same order as given in input
 */

#include "../boys/boy.h"
#include "../girls/girl.h"
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

    std::vector<Boy>  boys  = readAllBoys(BOY_FILE);
    std::vector<Girl> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift> gifts = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 2", true);
    logger.log("boys", std::to_string(boys.size()) + " record read");
    logger.log("girls", std::to_string(girls.size()) + " record read");
    logger.log("gifts", std::to_string(gifts.size()) + " record read");

    std::vector<Couple> couples = makeCouples(&boys, &girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed");

    if (k > (int)couples.size()) {
        logger.log("Error", "K is more than couples", true);
        return 1;
    }

    std::vector<Couple> hc = getKHappiestCouples(couples, k);
    logger.info(std::to_string(k)+ " happiest Couples list", true);
    for (int i = 0; i < (int)hc.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   hc[i].boy.name+" and "+hc[i].girl.name, true);

    std::vector<Couple> cc = getKCompatibleCouples(couples, k);
    logger.info(std::to_string(k) + " most compatible couples", true);
    for (int i = 0; i < (int)cc.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   cc[i].boy.name+" and "+cc[i].girl.name, true);

    return 0;
}
