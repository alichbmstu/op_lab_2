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
    returns res;
    QString file_name = QFileDialog::getOpenFileName(this, tr("Choose file"),
                                                     "D:/Users/Alya/Documents/op_lab_2",
                                                     tr("Only CSV(*.csv)"));
    ui->lbl_file->setText(file_name);
    if (file_name == "") {
        res.err=file_error;
        one_enter(QM, res);
    } else{
        ui->btn_upload->setEnabled(true);
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
    one_enter(QM, res);
    ui->btn_upload->setEnabled(true);
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
    one_enter(QM, res);
    ui->btn_calc->setEnabled(true);
}
