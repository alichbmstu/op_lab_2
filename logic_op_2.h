#ifndef LOGIC_OP_2_H
#define LOGIC_OP_2_H

#define WORK 60

#include <fstream>

using namespace std;

enum error{
    no_error,
    memory_error,
    calc_error
};

typedef struct{
    string file_name;
    string region;
    string param;
    int flag;
}logic;

typedef struct{
    char ***data;
    char ***choosen_data;
    char **choosen_arr;
    char **headers; //yes
    char **combo_boxik_with_regions; //yes
    int len_of_all_table; //yes
    int len_of_choosen_arr;
    int num_col_reg; //yes
    int how_many_cols_in_table; //yes
    string min;
    string med;
    string max;
    error err; //yes
}returns;

returns calc(logic base);
string search_region(int num_col_reg, string full);
void read_headers(logic &base, returns &res);
void regions_to_combo_box(logic &base, returns &res);
void free_matrix_memory(string **matrix, int rows);
string **alloc_memory_matrix(returns &res);
void read_all_data(logic &base, returns &res);
void only_chosen_region(logic &base, returns &res);
void free_three_point_matrix(char ***arr, int a1, int a2);
void calc_max_med_min(returns &res);
char **sorting(double **arr, int end);

#endif // LOGIC_OP_2_H
