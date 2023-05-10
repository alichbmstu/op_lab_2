//#include "ui_check.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <sstream>
//вывод в интерфейс

void MainWindow::region_data_put_on_table(returns res){
    ifstream file(res.file_name);
    int i=0, j=0;
    string full, piece;
    getline(file, full);
    ui->table_file->setRowCount(res.len_of_all_table);
    ui->table_file->setColumnCount(res.how_many_cols_in_table);
    while (getline(file, full)){
          stringstream ss(full);
          while (getline(ss, piece, ',')){
                ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(piece)));
                j++;
          }
          i++;
          j=0;
    }
}
