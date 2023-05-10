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
    //string header;
    string file_name;
    int choosed_col_num;
    string *data;
    error e;
}logic;

typedef struct{
    char ***data;
    string *headers;
    string *combo_boxik_with_regions;
    int len_of_all_table;
    int num_col_reg;
    int how_many_cols_in_table;
    double min;
    double med;
    double max;
}returns;

returns calc(logic base);
string search_region(int num_col_reg, string full);
void read_headers(logic &base, returns &res);

#endif // LOGIC_OP_2_H
