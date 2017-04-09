/* solver for ques 10
 * make couples and perform gifting using randomK
 */

#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include "../gifts/gift.h"
#include "../couples/couple.h"
#include "../utils/read_data.h"
#include "../utils/logger/logger.h"
#include "../templates/kbest.h"
#include "../templates/randomK.h"
#include "../configs.h"

std::vector<Couple> makeCouples(int k, std::vector<Boy*>, std::vector<Girl*>, Logger *logger);
void performGifting (int k, std::vector<Couple> *couples, std::vector<Gift> *giftlist, Logger *logger);

int main(int argc, char **argv)
{
    int k = K;
    if (argc >= 2)
        k = atoi(argv[1]);
    Logger logger(LOG_FILE);

    std::vector<Boy*>  boys  = readAllBoys(BOY_FILE);
    std::vector<Girl*> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift> gifts  = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 3", true);
    logger.log("boys", std::to_string(boys.size()) + " record read", true);
    logger.log("girls", std::to_string(girls.size()) + " record read", true);
    logger.log("gifts", std::to_string(gifts.size()) + " record read", true);

    std::vector<Couple> couples = makeCouples(k, boys, girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed", true);

    logger.info("Couples list", true);
    for (int i = 0; i < (int)couples.size(); i++)
        logger.log("couple"+std::to_string(i+1),
                   couples[i].boy->name+" and "+couples[i].girl->name, true);

    performGifting(k, &couples, &gifts, &logger);

    return 0;
}

std::vector<Couple> makeCouples(int k, std::vector<Boy*> boys, std::vector<Girl*> girls, Logger *logger)
{
    std::vector<Couple> couples;
    couples.clear();

    for (int j = 0; j < girls.size(); j++) {
        auto girl = RandomK<Girl*>(girls).getRandomElem();
        if (girl->committed) continue;

        std::vector<Boy*> topBoys;
        switch (girl->boy_type) {
        case attractive:
            topBoys = KBest<Boy*>(boys).getKBest(k, compareOnAttractiveness);
            break;
        case rich:
            topBoys = KBest<Boy*>(boys).getKBest(k, compareOnRichness);
            break;
        case intelligent:
            topBoys = KBest<Boy*>(boys).getKBest(k, compareOnIntelligence);
            break;
        }

        for (int i = 0; i < topBoys.size(); i++) {
            auto boy = RandomK<Boy*>(topBoys).getRandomElem();
            if (boy->committed) continue;
            if (boy->isCompatible(girl) &&
                girl->isCompatible(boy)) {

                couples.push_back(Couple(boy, girl));
                boy->committed = true;
                girl->committed= true;
                break;
            }
        }
    }

    return couples;
}

void performGifting (int k, std::vector<Couple> *couples, std::vector<Gift> *giftlist, Logger *logger)
{
    for (auto it = couples->begin(); it != couples->end(); it++)
        it->makeGiftBasket(*giftlist, logger);
}
