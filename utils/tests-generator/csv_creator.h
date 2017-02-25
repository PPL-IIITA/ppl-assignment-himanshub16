#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#ifndef CSV_CREATOR_H
#define CSV_CREATOR_H

class CSVCreator
{
private:
  std::vector <std::string> headers;
  std::vector <int> min_value;
  std::vector <int> max_value;
  std::string filename;
  std::string type;
  int fields;

  int get_random_int(int min, int max);
public:
  CSVCreator(std::string filename,
             std::string type,
             std::vector<std::string> headers,
             std::vector<int> min_value,
             std::vector<int> max_value);

  void generate(int n);
};

#endif
