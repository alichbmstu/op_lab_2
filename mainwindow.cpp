#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "QFileDialog"
#include "QMessageBox"

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
    int ooooooooo=1;
    char puk;

}

