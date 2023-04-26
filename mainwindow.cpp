#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QFileDialog"
#include "logic_op_2.h"
#include "QMessageBox"
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_choose_file_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose file"),
                                                     "D:/Users/Alya/Documents/op_lab_2",
                                                     tr("Only CSV(*.csv)"));
    ui->lbl_file->setText(file_name);
    // если файл не выбран - убирать, выбран включаем кнопки if (filname=="" && )
}


void MainWindow::on_btn_upload_clicked()
{
    string file_name =  ui->lbl_file->text().toStdString();
    string line;
    int *num_col_reg;
    read_headers(file_name, num_col_reg);
    regions_to_combo_box(file_name, num_col_reg);
    //data_region_to_table;
}

void MainWindow::regions_to_combo_box(){};

void MainWindow::read_headers(string file_name, int *num_col_reg){
    ifstream file(file_name);
    QStringList headers;
    int col_int=0;
    string header_str, h;
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(ss, h, ',')){
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::fromStdString(h));
        ui->table_file->setItem(0, col_int, item);
        if (h == "region")
            num_col_reg=&col_int;
        else
            headers.append(QString::fromStdString(h));
        col_int++;
    }
    ui->cmb_columns->addItems(headers);
}
















//string MainWindow::dowland_smth(string file_name, int &count){
//    ifstream file(file_name);
//    string line;
//    string str;
//    if (file.is_open()){
//        getline(file, line);
//        stringstream ss(line);
//    }
//    return line;
//}


//void MainWindow::set_line_into_table(std::string line, int line_int, QStringList *region){
//    stringstream ss(line);
//    string str;
//    int col_int = 0;
//    while (getline(ss, str, ',')){
//        QTableWidgetItem *item = new QTableWidgetItem();
//        item->setText(QString::fromStdString(str));
//        if (ui->table_file->horizontalHeaderItem(col_int)->text() == "region")
//            region->append(QString::fromStdString(str));
//        ui->table_file->setItem(line_int, col_int, item);
//        col_int++;
//    }
//}
