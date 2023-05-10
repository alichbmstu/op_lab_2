#include "logic_op_2.h"
#include <sstream>

//бизнес-логика


void read_headers(logic &base, returns &res);

returns calc(logic base){
    ifstream file (base.file_name);
    returns res;
    int i, j;
    // read all data (region/cols)
    read_headers(base, res);
    // read with region
    // calc metrics
    //вопрос по расположению функций
    return res;
}

void read_headers(logic &base, returns &res){
    ifstream file(base.file_name); //открываем файл
    res.headers = (string *) malloc (40); //массив под заголовки
    string header_str, h; //вспомагательные
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(ss, h, ',')){ //пока делится запятыми
        res.headers[res.how_many_cols_in_table] = h; //в массив хэдеров добавляем поделение название колонок
        if (h == "region"){
            res.num_col_reg = res.how_many_cols_in_table; // номер столбца региона
        }
        res.how_many_cols_in_table++;
    }
}

string search_region(int num_col_reg, string full){ //отделяю название региона от остальной строки
    int *z_arr = (int *)malloc(150); //массив для позиций запятых
    int z_cnt = 0;
    string res;
    for (int i=0;i<full.length();i++){
        if (full[i]==','){
           z_arr[z_cnt]=i; //позиции запятых в массив
           z_cnt++; //номер запятой
        }
    }
    res = full.substr(z_arr[num_col_reg-1]+1, z_arr[num_col_reg]-z_arr[num_col_reg-1]-1); //отделяю название региона
    free(z_arr);
    return res;
}


