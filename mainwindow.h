#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;

private slots: // Метод слот. Ничего не возварщает
    void digits_numbers();// Название.
    void on_pushButton_dot_clicked();
    void operations();
    void on_pushButton_ce_clicked();
    void on_pushButton_equals_clicked();
    void math_operation();
};
#endif // MAINWINDOW_H
