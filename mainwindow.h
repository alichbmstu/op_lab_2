#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logic_op_2.h"
//#include "ui_check.h"
#include <QMainWindow>

using namespace std;

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

    void on_cmb_region_currentTextChanged(const QString &arg1);

private:
    //void only_chosen_region(returns res);
    void region_only_put_on_table(returns res);
    string check_region(int num_col_reg, string full);
    void region_data_put_on_table(returns res);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
