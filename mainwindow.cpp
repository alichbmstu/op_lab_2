#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "logic_op_2.h"
//#include "ui_check.h"
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
    if (file_name == "") {
        QMessageBox::information(this,"Error", "Please choose file");
    }
}

void MainWindow::on_btn_calc_clicked()
{
    logic base;
    returns res;
    base.file_name =  ui->lbl_file->text().toStdString();
    base.region = ui->cmb_region->currentText().toStdString();
    base.param = ui->cmb_columns->currentText().toStdString();
    base.flag = 1;
    res = calc(base);
    one_enter(PUT_REG, res);
    one_enter(MMM, res);
}

void MainWindow::on_btn_upload_clicked()
{
    logic base;
    returns res;
    base.flag = 0;
    base.file_name =  ui->lbl_file->text().toStdString();
    res = calc(base);
    one_enter(CMB_REG, res);
    one_enter(SMTH_TABLE, res);
}



//void MainWindow::region_data_put_on_table(string file_name, int col_int, int len){
//    ifstream file(file_name);
//    int i=0, j=0;
//    string full, piece;
//    getline(file, full);
//    ui->table_file->setRowCount(len);
//    ui->table_file->setColumnCount(col_int);
//    while (getline(file, full)){
//          //string *datas = (string *)malloc(col_int);
//          stringstream ss(full);
//          while (getline(ss, piece, ',')){
//                ui->table_file->setItem(i, j, new QTableWidgetItem(QString::fromStdString(piece)));
//                j++;
//          }
//          i++;
//          j=0;
//          //free(datas);
//    }
//}


void MainWindow::on_cmb_region_currentTextChanged(const QString &arg1)
{
    logic lek;
    returns rek;
    //lek.region = (ui->lbl_num_col->text()).toStdString();
    //region_only_put_on_table(tek);
    //only_chosen_region(lek, rek);
}
