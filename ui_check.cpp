//#include "ui_check.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
//вывод в интерфейс

void MainWindow::region_data_put_on_table(returns res){
    ui->table_file->setRowCount(res.len_of_all_table);
    ui->table_file->setColumnCount(res.how_many_cols_in_table);
    for (int i=0; i<res.len_of_all_table; i++){
        for (int j=0;j<res.how_many_cols_in_table;j++){
            ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(res.data[i][j])));
        }
    }
    QStringList r;
    for (int y=0; y<res.combo_boxik_with_regions->length();y++){
        r.append(QString::fromStdString(res.combo_boxik_with_regions[y]));
    }
    ui->cmb_region->addItems(r);
}

void MainWindow::region_only_put_on_table(returns res){
    ui->table_file->setRowCount(200);
    ui->table_file->setColumnCount(res.how_many_cols_in_table);
    for (int i=0; i<200; i++){
        for (int j=0;j<res.how_many_cols_in_table;j++){
            ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(res.choosen_data[i][j])));
        }
    }
}
