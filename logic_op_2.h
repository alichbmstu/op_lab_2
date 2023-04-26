#ifndef LOGIC_OP_2_H
#define LOGIC_OP_2_H

#include <fstream>

using namespace std;

enum error{
    no_error,
    memory_error,
    calc_error
};

typedef struct{
    string region;
    string header;
    string file_name;
    double min;
    double med;
    double max;
    int column_num;
    int row_num;
    error e;
}logic;

typedef struct{
    char ***data;
    int column_num;
    int row_num;
}returns;

#endif // LOGIC_OP_2_H
