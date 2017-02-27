#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#ifndef CSV_CREATOR_H
#define CSV_CREATOR_H

/* Generatlized class to generate CSV file */
class CSVCreator
{
private:
    std::vector <std::string> headers;  /* Vector of headers of CSV file */
    std::vector <int> min_value;        /* List of min values for numeric arguments */
    std::vector <int> max_value;        /* List of max values for numeric arguments */
    std::string filename;               /* The filename to write CSV to */
    std::string type;                   /* The type of datas in CSV which becomes prefix of names */
    int fields;                         /* The number of fields in CSV file */

    /* Method to generate random number within a range */
    int get_random_int(int min, int max);
public:

    /* Constructor with CSV parameters as arguments */
    CSVCreator(std::string filename,
               std::string type,
               std::vector<std::string> headers,
               std::vector<int> min_value,
               std::vector<int> max_value);

    /* Method to generate CSV file */
    void generate(int n);
};

#endif
