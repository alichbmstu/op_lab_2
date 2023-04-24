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

private:
    void set_line_into_table(std::string line, int lineInt, QStringList *region);
    logic_first set_struct_first();
    string dowland_smth(string file_name, int &count);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
