#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logic_op_2.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_choose_file_clicked();

    void on_btn_upload_clicked();

    void on_btn_calc_clicked();

private:
    int read_headers(string file_name, int &col_int);
    int regions_to_combo_box(string file_name, int num_col_reg);
    void region_data_put_on_table(string file_name, int num_col_reg, int col_int, int len);
    string check_region(string file_name, int num_col_reg);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
