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
    string reg_act;
    int num_col_reg;
    num_col_reg = read_headers(file_name);
    regions_to_combo_box(file_name, num_col_reg);
    //ui->cmb_region->currentText();
    //data_region_to_table(file_name);
}

int MainWindow::regions_to_combo_box(string file_name, int num_col_reg){
    ifstream file(file_name);
    QStringList regions;
    string full, reg;
    int *z_arr = (int *)malloc(100);
    getline(file, full);
    while (getline(file, full)){
        int z_cnt=0;
        for (int i=0;i<full.length();i++){
            if (full[i]==','){
               z_arr[z_cnt]=i;
               // z_arr.push_back(i);
               z_cnt++;
            }
        }
        reg=full.substr(z_arr[num_col_reg-1]+1, z_arr[num_col_reg]-z_arr[num_col_reg-1]-1);
        regions.append(QString::fromStdString(reg));
    }
    regions.removeDuplicates();
    regions.sort();
    ui->cmb_region->addItems(regions);
    free(z_arr);
    return 0;
};

int MainWindow::read_headers(string file_name){
    int num_col_reg;
    ifstream file(file_name);
    int col_int=0;
    QStringList headers;
    string header_str, h;
    getline(file, header_str);
    stringstream ss(header_str);
    while (getline(ss, h, ',')){
        QTableWidgetItem *item = new QTableWidgetItem();
        item->setText(QString::fromStdString(h));
        ui->table_file->setItem(0, col_int, item);
        headers.append(QString::fromStdString(h));
        if (h == "region"){
            num_col_reg=col_int;
        }else{
            ui->cmb_columns->addItem(QString::fromStdString(h));
        }
        col_int++;
    }
    ui->table_file->setRowCount(1);
    ui->table_file->setColumnCount(col_int);
    ui->table_file->setHorizontalHeaderLabels(headers);
    return num_col_reg;
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
