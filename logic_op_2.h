#ifndef LOGIC_OP_2_H
#define LOGIC_OP_2_H

#define WORK 100

#include <fstream>

using namespace std;

enum error{
    no_error,
    memory_error,
    calc_error
};

typedef struct{
    string file_name;
    int flag;
    error err;
}logic;

typedef struct{
    string **data;
    string **choosen_data;
    char **headers;
    char **combo_boxik_with_regions;
    int len_of_all_table;
    int num_col_reg;
    int how_many_cols_in_table;
    double min;
    double med;
    double max;
    error err;
}returns;

returns calc(logic base);
string search_region(int num_col_reg, string full);
void read_headers(logic &base, returns &res);
void regions_to_combo_box(logic &base, returns &res);
void free_matrix_memory(string **matrix, int rows);
string **alloc_memory_matrix(returns &res);
void read_all_data(logic &base, returns &res);
void only_chosen_region(logic &base, returns &res);

#endif // LOGIC_OP_2_H
