#include "csv_creator.h"
#include "../configs.h"

int main(int argc, char **argv)
{
  if (argc < 4) {
    std::cout << "Insufficient arguments" << std::endl;
    std::cout << "./generate girls boys gifts" << std::endl;
    return 1;
  }

  int n_girls = atoi(argv[1]);
  std::vector<std::string> girls_attr;
    girls_attr.push_back("name");
    girls_attr.push_back("attractiveness");
    girls_attr.push_back("intelligence");
    girls_attr.push_back("budget");
    girls_attr.push_back("nature");
    girls_attr.push_back("boy_choice" );
  std::vector<int> girls_attr_min_values ({0, 0, 0, 0, 0});
  std::vector<int> girls_attr_max_values ({100, 100, 1000, 2, 2});

  int n_boys = atoi(argv[2]);
  std::vector<std::string> boys_attr;
    boys_attr.push_back("name");
    boys_attr.push_back("attractiveness");
    boys_attr.push_back("intelligence");
    boys_attr.push_back("budget");
    boys_attr.push_back("nature");
    boys_attr.push_back("min_attr_req");
  std::vector<int> boys_attr_min_values ({0, 0, 0, 0, 0});
  std::vector<int> boys_attr_max_values ({100, 100, 1000, 2, 100});

  int n_gifts = atoi(argv[3]);
  std::vector<std::string> gifts_attr;
    gifts_attr.push_back("name");
    gifts_attr.push_back("type");
    gifts_attr.push_back("price");
    gifts_attr.push_back("value");
  std::vector<int> gifts_attr_min_values ({0, 10, 0});
  std::vector<int> gifts_attr_max_values ({3, 1000, 100});

  CSVCreator girls(GIRL_FILE, "girl", girls_attr, girls_attr_min_values, girls_attr_max_values);
  girls.generate(n_girls);

  CSVCreator boys(BOY_FILE, "boy", boys_attr, boys_attr_min_values, boys_attr_max_values);
  boys.generate(n_boys);

  CSVCreator gifts(GIFT_FILE, "gift", gifts_attr, gifts_attr_min_values, gifts_attr_max_values);
  gifts.generate(n_gifts);

  return 0;
}
