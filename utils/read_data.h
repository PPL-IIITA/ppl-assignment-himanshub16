#ifndef READ_DATA_H
#define READ_DATA_H

#define CSV_IO_NO_THREAD
#include "csv-parser/csv.h"

#include "../girls/allgirls.h"
#include "../boys/allboys.h"
#include "../gifts/gift.h"

/* Read all boys from filename (CSV)
 * Return the vector of boys
 */
std::vector<Boy*> readAllBoys(std::string filename)
{
    io::CSVReader<6> in(filename.c_str());
    in.read_header(io::ignore_extra_column,
                   "name",
                   "attractiveness",
                   "intelligence",
                   "budget",
                   "nature",
                   "min_attr_req");

    std::vector<Boy*> boys;
    boys.clear();

    std::string name;
    int attr, intel, budget, nature, min_attr;

    while (in.read_row(name, attr, intel, budget, nature, min_attr)) {
        switch(nature) {
        case BoyNature::miser:
            boys.push_back(new MiserBoy(name, attr, intel, budget, min_attr));
            break;
        case BoyNature::generous:
            boys.push_back(new GenerousBoy(name, attr, intel, budget, min_attr));
            break;
        case BoyNature::geek:
            boys.push_back(new GeekBoy(name, attr, intel, budget, min_attr));
            break;
        }
    }
    return boys;
}

/* Read all girls from filename (CSV)
 * Return the vector of Girls
 */
std::vector<Girl*> readAllGirls(std::string filename)
{
    io::CSVReader<6> in(filename.c_str());
    in.read_header(io::ignore_extra_column,
                   "name",
                   "attractiveness",
                   "intelligence",
                   "budget",
                   "nature",
                   "boy_choice");

    std::vector<Girl*> girls;
    girls.clear();

    std::string name;
    int attr, intel, budget, nature, boy_nature;

    while (in.read_row(name, attr, intel, budget, nature, boy_nature)) {
        switch (nature) {
        case GirlNature::choosy:
            girls.push_back(new ChoosyGirl(name, attr, intel, budget, static_cast<BoyType>(boy_nature)));
            break;
        case GirlNature::desperate:
            girls.push_back(new DesperateGirl(name, attr, intel, budget, static_cast<BoyType>(boy_nature)));
            break;
        case GirlNature::normal:
            girls.push_back(new NormalGirl(name, attr, intel, budget, static_cast<BoyType>(boy_nature)));
            break;
        }
    }
    return girls;
}

/* Read all Gifts from filename (CSV)
 * Returns the vector of Gifts
 */
std::vector<Gift> readAllGifts(std::string filename)
{
    io::CSVReader<4> in(filename.c_str());
    in.read_header(io::ignore_extra_column,
                   "name",
                   "type",
                   "price",
                   "value");

    std::vector<Gift> gifts;
    gifts.clear();

    std::string name;
    int type, price, value;

    while (in.read_row(name, type, price, value)) {
        gifts.push_back(Gift(name,
                             static_cast<GiftType>(type),
                             price,
                             value));
    }
    return gifts;
}

#endif
