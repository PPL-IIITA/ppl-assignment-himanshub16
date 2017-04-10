/** q7 : search and tell if any of
    the boys in a list have girlfriends
*/

#include "../boys/allboys.h"
#include "../girls/allgirls.h"
#include "../gifts/gift.h"
#include "../couples/couple.h"
#include "../utils/read_data.h"
#include "../utils/couple_utils.h"
#include "../search/all_search.h"
#include "../utils/logger/logger.h"

#include "../configs.h"

#include <cstdlib>
#include <ctime>

std::vector<std::string> getNamesToSearch(int nNames, int nBoys);

int main(int argc, char **argv)
{
    /* Search Methods:
     * 1: linear search
     * 2: binary search
     * 3: hash   search
     */
    int searchMethod = 1;
    if (argc >= 2)
        searchMethod = atoi(argv[1]);
    Logger logger(LOG_FILE);

    std::vector<Boy*>  boys  = readAllBoys (BOY_FILE);
    std::vector<Girl*> girls = readAllGirls(GIRL_FILE);
    std::vector<Gift>  gifts = readAllGifts(GIFT_FILE);

    logger.info("Processing for question 5", true);
    logger.log("boys", std::to_string(boys.size()) + " record read", true);
    logger.log("girls", std::to_string(girls.size()) + " record read", true);
    logger.log("gifts", std::to_string(gifts.size()) + " record read", true);

    std::vector<Couple> couples = makeCouples(boys, girls, &logger);

    logger.log("couples", std::to_string(couples.size()) + " formed", true);

    Search *search;
    switch (searchMethod) {
    case 2:
        search = new BinarySearch(boys);
        break;
    case 3:
        search = new HashSearch(boys);
        break;
    case 1:
    default:
        search = new ArraySearch(boys);
        break;
    }

    int nBoys = boys.size();
    std::vector<std::string> namelist = getNamesToSearch(nBoys/2, nBoys*1.5);
    logger.info("Created list of boys to search for", true);

    for (auto name : namelist) {
        std::cout << name << ' ';
    }
    std::cout << std::endl;

    search->findGirlfriends(namelist, &logger);

    return 0;
}

/** Returns a random list of names of boys to search against in boyslist */
std::vector<std::string> getNamesToSearch(int size, int nBoys)
{
    std::vector< std::string > randomNames;
    randomNames.clear();
    std::srand(std::time(0));

    while (size--) {
        randomNames.push_back("boy-"+std::to_string( std::rand()%nBoys ));
    }
    return randomNames;
}
