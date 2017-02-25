#ifndef CSV_CREATOR_H
#include "csv_creator.h"
#endif

#include <stdexcept>

CSVCreator::CSVCreator(std::string filename,
           std::string type,
           std::vector<std::string> headers,
           std::vector<int> min_value,
           std::vector<int> max_value)
{
  if (headers.size()-1 != min_value.size() ||
      headers.size()-1 != max_value.size())
    throw std::invalid_argument ("Parameters of unequal length");

  this->fields    = headers.size();
  this->filename  = filename;
  this->type      = type;
  this->headers   = headers;
  this->min_value = min_value;
  this->max_value = max_value;
}

void CSVCreator::generate(int n)
{
  std::fstream file(this->filename.c_str(), std::ios::out | std::ios::trunc);

  /* some variables which will be required later */
  std::vector <std::string>::iterator str_it;
  std::vector <int>::iterator int_it;
  int i, j;

  /* write all the headers */
  for (i = 0; i < this->fields; i++)
    file << this->headers[i] << ',';
  file << std::endl;

  /* write data */
  for (i = 0; i < n; i++) {
    file << this->type << i << ',';
    for (j = 1; j < this->fields; j++)
      file << get_random_int(this->min_value[j], this->max_value[j]) << ',';
    file << std::endl;
  }
  file.close();
}

int CSVCreator::get_random_int(int min, int max)
{
  return min + (rand() % (max-min+1));
}
