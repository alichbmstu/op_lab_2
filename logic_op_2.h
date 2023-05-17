#ifndef LOGIC_OP_2_H
#define LOGIC_OP_2_H

#define WORK 50
#define STR 28

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
    char **headers;
    char **combo_boxik_with_regions;
    string min;
    string max;
    float med;
    int len_of_all_table;
    int len_of_choosen_arr;
    int num_col_reg;
    int how_many_cols_in_table;
    error err;
}returns;

returns calc(logic base);
void select_data_for_output(logic base, returns &res);
void read_data_from_parameter(logic base, returns &res);
void swap(char **a, char **b);
char **sorting(char **arr, int end);
void read_headers(string filename, returns &res);
string search_region(int num_col_reg, string full);
void regions_to_combo_box(string filename, returns &res);
void free_matrix_memory(char **matrix, int rows);
void  free_three_point_matrix(char ***arr, int a1, int a2);
char **alloc_memory_matrix(int rows, int cols, returns &res);
char ***alloc_memory_three_point_matrix(int rows, int cols, returns &res);
void data_to_table(string filename, returns &res);
void only_chosen_region(logic &base, returns &res);
void calc_max_med_min(returns &res);

#endif // LOGIC_OP_2_H
