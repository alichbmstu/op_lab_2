#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//вывод в интерфейс

void put_cmb(returns res);

QStringList do_list(char **mas, int len);

void MainWindow::one_enter(int flag_a, returns res){
    if (flag_a == CMB_REG){
        put_cmb(res);
    }
}


void MainWindow::put_cmb(returns res){
     QStringList arr_c;
     arr_c= do_list(res.combo_boxik_with_regions, res.len_of_all_table);
     ui->cmb_region->addItems(arr_c);
     QStringList arr_h;
     arr_h= do_list(res.headers, res.how_many_cols_in_table);
     ui->cmb_columns->addItems(arr_h);
}

QStringList do_list(char ** mas, int len){
    QStringList arr;
    string h;
    for (int i=0; i<len;i++){
        h = (string) mas[i];
        if (h!="region"){
            arr.append(QString::fromStdString(h));
        }
    }
    arr.removeDuplicates();
    arr.sort();
    return arr;
}

void MainWindow::region_data_put_on_table(returns res){
//    ui->table_file->setRowCount(res.len_of_all_table);
//    ui->table_file->setColumnCount(res.how_many_cols_in_table);
//    for (int i=0; i<res.len_of_all_table; i++){
//        for (int j=0;j<res.how_many_cols_in_table;j++){
//            ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(res.data[i][j])));
//        }
//    }
//    QStringList r;
//    for (int y=0; y<res.combo_boxik_with_regions->length();y++){
//        r.append(QString::fromStdString(res.combo_boxik_with_regions[y]));
//    }
//    ui->cmb_region->addItems(r);
}

void MainWindow::region_only_put_on_table(returns res){
//    ui->table_file->setRowCount(200);
//    ui->table_file->setColumnCount(res.how_many_cols_in_table);
//    for (int i=0; i<200; i++){
//        for (int j=0;j<res.how_many_cols_in_table;j++){
//            ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(res.choosen_data[i][j])));
//        }
//    }
}
