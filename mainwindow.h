#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logic_op_2.h"
#include <QMainWindow>
#define CMB_REG 5
#define CUR_REG 6
#define SMTH_TABLE 7
#define CMB_PAR 8
#define PUT_REG 9
#define MMM 10
#define QM 11
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

private:

    void one_enter(int flag_a, returns res);
    void put_cmb(returns res);
    void metrics_to_ui(returns res);
    void any_errors(returns res);
    void data_put_on_table(char ***data, returns res, int rows);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
