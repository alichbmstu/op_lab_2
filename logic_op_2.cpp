#include "logic_op_2.h"
//#include "mainwindow.h"
#include <sstream>
//бизнес-логика


void read_headers(logic &base, returns &res);
string search_region(int num_col_reg, string full);
void regions_to_combo_box(logic &base, returns &res);
void free_matrix_memory(string **matrix, int rows);
string **alloc_memory_matrix(returns &res);
void read_all_data(logic &base, returns &res);
void only_chosen_region(logic &base, returns &res);

returns calc(logic base){
    //ifstream file (base.file_name);
    returns res;
    //int i, j;
    // read all data (region/cols)
    read_headers(base, res);
    //region_data_put_on_table(res);
    regions_to_combo_box(base, res);
    read_all_data(base, res);
    // read with region
    // calc metrics
    //вопрос по расположению функций
    return res;
}

void read_all_data(logic &base, returns &res){
    ifstream file(base.file_name);
    int i, j;
    string header_str, full, piece;
    res.data=alloc_memory_matrix(res);
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(file, full)){
          stringstream ss(full);
          while (getline(ss, piece, ',')){
                res.data[i][j]=piece;
                j++;
          }
          i++;
          j=0;
    }
}

string **alloc_memory_matrix(returns &res) {
    string **mat = (string **) malloc(res.len_of_all_table * sizeof(string *));
    if (mat != NULL) {
        for (int i = 0; i < res.len_of_all_table; i++) {
            *(mat + i) = (string *) malloc(res.how_many_cols_in_table * sizeof(string));
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

void free_matrix_memory(string **matrix, int rows) {
    for (int i = 0; i < rows; i++)
        free(*(matrix + i));
    free(matrix);
}

void read_headers(logic &base, returns &res){
    ifstream file(base.file_name); //открываем файл
    res.headers = (string *) malloc (100); //массив под заголовки
    string header_str, h; //вспомагательные
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(ss, h, ',')){ //пока делится запятыми
        res.headers[res.how_many_cols_in_table] = h; //в массив хэдеров добавляем поделенные название колонок
        if (h == "region"){
            res.num_col_reg = res.how_many_cols_in_table; // номер столбца региона
        }
        res.how_many_cols_in_table++;
    }
}

void regions_to_combo_box(logic &base, returns &res){
    ifstream file(base.file_name);
    res.combo_boxik_with_regions = (string *) malloc (ALL); // init массив
    string full, reg;
    int len=0;
    getline(file, full); //убираю хэдр
    while (getline(file, full)){
            reg = search_region(res.num_col_reg, full); // ищу регион
            res.combo_boxik_with_regions[len]=reg; // регион добавляю в комбобокс
            len++;
    }
    res.len_of_all_table = len;
    //ui->cmb_region->addItems(regions);
};

void only_chosen_region(logic &base, returns &res){
    ifstream file(base.file_name);
    //ui->table_file->clear();
    int i=0,u, j=0;
    res.choosen_data = alloc_memory_matrix(res);
    string cur_reg = base.region;
    string full, reg_from_table, piece;
    getline(file, full);
    //ui->table_file->setRowCount(100);
    //ui->table_file->setColumnCount(7); //пока так надо убрать
    while (getline(file, full)){
        reg_from_table = search_region(res.num_col_reg, full);
        if (reg_from_table==cur_reg){
            stringstream ss(full);
            while (getline(ss, piece, ',')){
                  res.choosen_data[i][j]=piece;
                  //ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(piece)));
                  j++;
            }
            i++;
            j=0;
        }
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


