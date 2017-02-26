#ifndef READ_DATA_H
#define READ_DATA_H

#define CSV_IO_NO_THREAD
#include "csv-parser/csv.h"

#include "../girls/girl.h"
#include "../boys/boy.h"
#include "../gifts/gift.h"

std::vector<Boy> readAllBoys(char *filename)
{
    io::CSVReader<6> in(filename);
    in.read_header(io::ignore_extra_column,
                   "name",
                   "attractiveness",
                   "intelligence",
                   "budget",
                   "nature",
                   "min_attr_req");

    std::vector<Boy> boys;
    boys.clear();

    std::string name;
    int attr, intel, budget, nature, min_attr;

    while (in.read_row(name, attr, intel, budget, nature, min_attr)) {
        boys.push_back(Boy(name,
                           static_cast<BoyNature>(nature),
                           attr,
                           intel,
                           budget,
                           min_attr));
    }
    return boys;
}

std::vector<Girl> readAllGirls(char *filename)
{
    io::CSVReader<6> in(filename);
    in.read_header(io::ignore_extra_column,
                   "name",
                   "attractiveness",
                   "intelligence",
                   "budget",
                   "nature",
                   "boy_choice");

    std::vector<Girl> girls;
    girls.clear();

    std::string name;
    int attr, intel, budget, nature, boy_nature;

    while (in.read_row(name, attr, intel, budget, nature, boy_nature)) {
        girls.push_back(Girl(name,
                             attr,
                             intel,
                             budget,
                             static_cast<GirlNature>(nature),
                             static_cast<BoyType>(boy_nature)
                        ));
    }
    return girls;
}

std::vector<Gift> readAllGifts(char *filename)
{
    io::CSVReader<4> in(filename);
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
