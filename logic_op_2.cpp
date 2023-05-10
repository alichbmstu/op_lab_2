#include "logic_op_2.h"
#include <sstream>

//������-������


void read_headers(logic &base, returns &res);

returns calc(logic base){
    ifstream file (base.file_name);
    returns res;
    int i, j;
    // read all data (region/cols)
    read_headers(base, res);
    // read with region
    // calc metrics
    //����� �� �ᯮ������� �㭪権
    return res;
}

void read_headers(logic &base, returns &res){
    ifstream file(base.file_name); //���뢠�� 䠩�
    res.headers = (string *) malloc (40); //���ᨢ ��� ���������
    string header_str, h; //�ᯮ����⥫��
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(ss, h, ',')){ //���� ������� �����묨
        res.headers[res.how_many_cols_in_table] = h; //� ���ᨢ ��஢ ������塞 ��������� �������� �������
        if (h == "region"){
            res.num_col_reg = res.how_many_cols_in_table; // ����� �⮫�� ॣ����
        }
        res.how_many_cols_in_table++;
    }
}

string search_region(int num_col_reg, string full){ //�⤥��� �������� ॣ���� �� ��⠫쭮� ��ப�
    int *z_arr = (int *)malloc(150); //���ᨢ ��� ����権 �������
    int z_cnt = 0;
    string res;
    for (int i=0;i<full.length();i++){
        if (full[i]==','){
           z_arr[z_cnt]=i; //����樨 ������� � ���ᨢ
           z_cnt++; //����� ����⮩
        }
    }
    res = full.substr(z_arr[num_col_reg-1]+1, z_arr[num_col_reg]-z_arr[num_col_reg-1]-1); //�⤥��� �������� ॣ����
    free(z_arr);
    return res;
}


