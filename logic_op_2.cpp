#include "logic_op_2.h"
//#include "mainwindow.h"
#include <cstring>
#include <sstream>
//������-������


void read_headers(logic &base, returns &res);
string search_region(int num_col_reg, string full);
void regions_to_combo_box(logic &base, returns &res);
void free_matrix_memory(char **matrix, int rows, int cols);
char **alloc_memory_matrix(char **matrix, int rows, int cols, returns &res);
void read_all_data(logic &base, returns &res);
void only_chosen_region(logic &base, returns &res);

returns calc(logic base){
    returns res;
    if (base.flag!=100){
        read_headers(base, res);
        ///headers_to_combo_box *ui
        regions_to_combo_box(base, res);
        ///data_to_table *ui
    }
    ///read_data_with_region + ui
    /// read_data_from_parameter
    /// calc_max_med_min + ui
    // read all data (region/cols)
    //read_all_data(base, res);
    // read with region
    // calc metrics
    return res;
}

//void read_all_data(logic &base, returns &res){
//    ifstream file(base.file_name);
//    int i, j;
//    string header_str, full, piece;
//    getline(file, header_str);
//    stringstream ss(header_str);
//    while (getline(file, full)){
//          stringstream ss(full);
//          while (getline(ss, piece, ',')){
//                res.data[i][j]=piece;
//                j++;
//          }
//          i++;
//          j=0;
//    }
//}
//char **alloc_memory_matrix(char **matrix, int rows, int cols) {
//    char **mat = (char **) malloc(res.len_of_all_table * sizeof(char *));
//    if (mat != NULL) {
//        for (int i = 0; i < res.len_of_all_table; i++) {
//            *(mat + i) = (char *) malloc(res.how_many_cols_in_table * sizeof(char));
//            if (*(mat + i) == NULL) {
//                free_matrix_memory(mat, i - 1);
//                mat = NULL;
//                res.err=memory_error;
//                break;
//            }
//        }
//    } else {
//        res.err=memory_error;
//    }
//    return mat;
//}
char **alloc_memory_matrix(char **matrix, int rows, int cols, returns &res) {
    char **mat = (char **) malloc(rows * sizeof(char *));
    if (mat != NULL) {
        for (int i = 0; i < rows; i++) {
            *(mat + i) = (char *) malloc(cols * sizeof(char));
            if (*(mat + i) == NULL) {
                free_matrix_memory(mat, i - 1, 1);
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

void free_matrix_memory(char **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++)
        free(*(matrix + i));
    free(matrix);
}

void read_headers(logic &base, returns &res){
    ifstream file(base.file_name); //���뢠�� 䠩�
    char **headers; //���ᨢ ��� ��������� //char*
    headers = alloc_memory_matrix(headers, WORK, WORK, res);
    res.how_many_cols_in_table=0;
    if (headers != NULL) {
        string header_str, h; //�ᯮ����⥫��
        getline(file, header_str);
        stringstream ss(header_str);
        while (getline(ss, h, ',')){ //���� ������� �����묨
            //auto ptr = headers + res.how_many_cols_in_table;
            strcpy(headers[res.how_many_cols_in_table], h.c_str()); //� ���ᨢ ��஢ ������塞 ��������� �������� �������
            if (h == "region"){
                res.num_col_reg = res.how_many_cols_in_table; // ����� �⮫�� ॣ����
            }
            res.how_many_cols_in_table++;
        }
    }
    res.headers = headers;
}

void regions_to_combo_box(logic &base, returns &res){
    ifstream file(base.file_name);
    char **regi; // init ���ᨢ
    regi = alloc_memory_matrix(regi, WORK*WORK, WORK*WORK, res);
    string full;
    char *reg;
    string s_reg;
    int len=0;
    getline(file, full); //㡨�� ���
    while (getline(file, full)){
            s_reg = search_region(res.num_col_reg, full); // ��� ॣ���
            strcpy(regi[len], s_reg.c_str());
            //auto ptr = regi + len;
            //regi[len]=reg; // ॣ��� �������� � ���������
            len++;
    }
    res.len_of_all_table = len;
    res.combo_boxik_with_regions = regi;
    //ui->cmb_region->addItems(regions);
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
//    //ui->table_file->setColumnCount(7); //���� ⠪ ���� ����
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



string search_region(int num_col_reg, string full){ //�⤥��� �������� ॣ���� �� ��⠫쭮� ��ப�
    int *z_arr = (int *)malloc(WORK*sizeof(int)); //���ᨢ ��� ����権 �������
    int z_cnt = 0;
    string res;
    for (int i=0;i<full.length();i++){
        if (full[i]==','){
           z_arr[z_cnt]=i; //����樨 ������� � ���ᨢ
           z_cnt++; //����� ����⮩
        }
    }
    res = full.substr(z_arr[num_col_reg-1]+1, z_arr[num_col_reg]-z_arr[num_col_reg-1]-1); //�⤥��� �������� ॣ����
    //char *u;
    //free(z_arr);
    return res;
}


