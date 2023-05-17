#include <QMainWindow>
#include "mainwindow.h"
#include "ui_mainwindow.h"
//вывод в интерфейс

void put_cmb(returns res);

QStringList do_list(char **mas, int len, int flag);

void MainWindow::one_enter(int flag_a, returns res){ //убрать из класса
    ui->table_file->setEditTriggers(QAbstractItemView::NoEditTriggers);
    if (flag_a == CMB_REG)
        put_cmb(res);
    if (flag_a == SMTH_TABLE)
        data_put_on_table(res.data, res, WORK);
    if (flag_a == PUT_REG)
        data_put_on_table(res.choosen_data, res, STR);
    if (flag_a == MMM)
        metrics_to_ui(res);
}

void MainWindow::metrics_to_ui(returns res){
    ui->lbl_min_num->setText(QString::fromStdString(res.min));
    ui->lbl_med_num->setText(QString::number(res.med, 'l', 1));
    ui->lbl_max_num->setText(QString::fromStdString(res.max));
}


void MainWindow::put_cmb(returns res){
     QStringList arr_c;
     arr_c= do_list(res.combo_boxik_with_regions, res.len_of_all_table,CMB_REG);
     ui->cmb_region->addItems(arr_c);
     QStringList arr_h;
     arr_h= do_list(res.headers, res.how_many_cols_in_table, CMB_PAR);
     ui->cmb_columns->addItems(arr_h);
}

QStringList do_list(char **mas, int len, int flag){
    QStringList arr;
    string h;
    for (int i=0; i<len;i++){
        h = (string) mas[i];
        if (h!="region" && (flag==CMB_REG || flag==CMB_PAR)){
                    arr.append(QString::fromStdString(h));
        } else if (flag == SMTH_TABLE){
                    arr.append(QString::fromStdString(h));
                }
    }
    if (flag==CMB_REG){
        arr.removeDuplicates();
        arr.sort();
    }
    return arr;
}

void MainWindow::data_put_on_table(char ***data, returns res, int rows){
    ui->table_file->clear();
    ui->table_file->setRowCount(rows);
    ui->table_file->setColumnCount(res.how_many_cols_in_table);
    QStringList arr_h;
    arr_h= do_list(res.headers, res.how_many_cols_in_table, SMTH_TABLE);
    ui->table_file->setHorizontalHeaderLabels(arr_h);
    string cur;
    for (int i = 0; i < rows; i++){
        for (int j = 0;j < res.how_many_cols_in_table; j++){
            cur = (string) data[i][j];
            ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(cur)));
        }
    }
}

