#include "logic_op_2.h"
#include <cstring>
#include <sstream>
//бизнес-логика


void read_headers(logic &base, returns &res);
string search_region(int num_col_reg, string full);
void regions_to_combo_box(logic &base, returns &res);
void free_matrix_memory(char **matrix, int rows);
char **alloc_memory_matrix(int rows, int cols, returns &res);
char ***alloc_memory_three_point_matrix(int rows, int cols, returns &res);
void data_to_table(logic &base, returns &res);
void only_chosen_region(logic &base, returns &res);
void read_data_from_parameter(logic &base, returns &res);

returns calc(logic base){
    returns res;
    if (base.flag!=10){
        read_headers(base, res);
        regions_to_combo_box(base, res);
        data_to_table(base, res);
    }
    if (base.flag==222){
        read_data_from_parameter(base, res);
        calc_max_med_min(res);
    }
    ///read_data_with_region + ui
    //read_all_data(base, res);
    // read with region
    // calc metrics
    return res;
}

void read_data_from_parameter(logic &base, returns &res){
    ifstream file(base.file_name);
    int len = 0;
    int j=0;
    for (int i=0; i<res.how_many_cols_in_table; i++){
        string t = (string)res.headers[i];
        if (t==base.param && t!="year")
            j=i+1;
        else if (t==base.param && t!="year")
            j=i;
    }

    //костыль, подумать


    char **params; //массив под значения параметра
    params = alloc_memory_matrix(WORK*10, res.how_many_cols_in_table, res); //добавить роус по региону
    string full, piece; //вспомагательные
    getline(file, full);
    if (params != NULL) {
        while (getline(file, full)){
            if (search_region(res.num_col_reg, full)==base.region){
                piece = search_region(j, full); // ищу регион
                strcpy(params[len], piece.c_str());
                len++;
            }
        }
    }
    res.choosen_arr = params;
}


int swap(double *ch1, double *ch2){
    double current;
    current=*ch1;
    *ch1=*ch2;
    *ch2=current;
    return *ch1, *ch2;
}

char **sorting(char **arr, int end){
    for (int i = 0; i < end-1; ++i)
        for (int j = 0; j < end-1; ++j)
            if (arr[i]<arr[i+1]){
                swap(*(arr+j), *(arr+j+1));
            }
    return arr;
}

void calc_max_med_min(returns &res){
    res.choosen_arr = sorting(res.choosen_arr, WORK);
    res.min =res.choosen_arr[0];
}


void data_to_table(logic &base, returns &res){
    ifstream file(base.file_name);
    string full, piece;
    res.data = alloc_memory_three_point_matrix(WORK, res.how_many_cols_in_table, res);
    getline(file, full);
    for (int i=0; i < WORK; i++){
        getline(file, full);
        stringstream ss(full);
        for (int j=0; j < res.how_many_cols_in_table;j++){
            getline(ss, piece, ',');
               strcpy(res.data[i][j], piece.c_str());
        }
    }
}

char***alloc_memory_three_point_matrix(int rows, int cols, returns &res){
    char ***data = (char ***)malloc(rows*sizeof(char**));
    if (data!=NULL){
        for (int i = 0; i < rows; i++){
            *(data+i) = (char **)malloc(WORK * sizeof(char*));
            if (*(data+i)==NULL){
                free_matrix_memory(*data,i-1);
                res.err=memory_error;
                data=NULL;
                break;
            }
            if (*(data+i)!=NULL){
                for (int j = 0; j < cols; j++){
                    *(*(data+i)+j)=(char *)malloc(WORK * sizeof(char));
                    if (*(*(data+i)+j)==NULL){
                        free_three_point_matrix(data,j-1,i);
                        res.err=memory_error;
                        data = NULL;
                        break;
                    }
                }
            }
        }
    } else {
        res.err=memory_error;
    }
    return data;
}

void free_three_point_matrix(char ***arr, int a1, int a2){
    for (int i = 0; i < a1; i++)
        free_matrix_memory(*(arr+i), a2);
    free(arr);
}

char **alloc_memory_matrix(int rows, int cols, returns &res) {
    char **mat = (char **) malloc(rows * sizeof(char *));
    if (mat != NULL) {
        for (int i = 0; i < rows; i++) {
            *(mat + i) = (char *) malloc(cols * sizeof(char));
            if (*(mat + i) == NULL) {
                free_matrix_memory(mat, i - 1);
                mat = NULL;
                res.err=memory_error;
                break;
            }
        }
    } else {
        res.err=memory_error;
    }
    return mat;
}

void free_matrix_memory(char **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(*(matrix + i));
    free(matrix);
}
///пустота не считается при подсчетах
void read_headers(logic &base, returns &res){
    ifstream file(base.file_name); //открываем файл
    char **headers; //массив под заголовки //char*
    headers = alloc_memory_matrix(WORK, WORK, res);
    res.how_many_cols_in_table=0;
    if (headers != NULL) {
        string header_str, h; //вспомагательные
        getline(file, header_str);
        stringstream ss(header_str);
        while (getline(ss, h, ',')){ //пока делится запятыми
            strcpy(headers[res.how_many_cols_in_table], h.c_str()); //в массив хэдеров добавляем поделенные название колонок
            if (h == "region"){
                res.num_col_reg = res.how_many_cols_in_table; // номер столбца региона
            }
            res.how_many_cols_in_table++;
        }
    }
    res.headers = headers;
}

void regions_to_combo_box(logic &base, returns &res){
    ifstream file(base.file_name);
    char **regi; // init массив
    regi = alloc_memory_matrix(WORK*WORK, WORK*WORK, res);
    string full, s_reg;
    int len=0;
    getline(file, full); //убираю хэдр
    while (getline(file, full)){
            s_reg = search_region(res.num_col_reg, full); // ищу регион
            strcpy(regi[len], s_reg.c_str());
            len++;
    }
    res.len_of_all_table = len;
    res.combo_boxik_with_regions = regi;
};

//void only_chosen_region(logic &base, returns &res){
//    ifstream file(base.file_name);
//    //ui->table_file->clear();
//    int i=0,u, j=0;
//  //  res.choosen_data = alloc_memory_matrix(res);
//    //string cur_reg = base.region;
//    string full, reg_from_table, piece;
//    getline(file, full);
//    //ui->table_file->setRowCount(100);
//    //ui->table_file->setColumnCount(7); //пока так надо убрать
//    while (getline(file, full)){
//        reg_from_table = search_region(res.num_col_reg, full);
//        if (reg_from_table==cur_reg){
//            stringstream ss(full);
//            while (getline(ss, piece, ',')){
//                  res.choosen_data[i][j]=piece;
//                  //ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(piece)));
//                  j++;
//            }
//            i++;
//            j=0;
//        }
//    }
//}



string search_region(int num_col_reg, string full){ //отделяю название региона от остальной строки
    int *z_arr = (int *)malloc(full.length()*sizeof(int)); //массив для позиций запятых //убрать 7
    int z_cnt = 0;
    string res;
    if (z_arr!=NULL){
        for (int i=0;i<full.length();i++){
            if (full[i]==','){
               z_arr[z_cnt]=i; //позиции запятых в массив
               z_cnt++; //номер запятой
            }
        }
        if (num_col_reg!=0)
            res = full.substr(z_arr[num_col_reg-1]+1, z_arr[num_col_reg]-z_arr[num_col_reg-1]-1); //отделяю название региона
        else
            res = full.substr(0, z_arr[num_col_reg]);
    }
    free(z_arr);
    return res;
}


