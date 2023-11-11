#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"


double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Нажание на кнопку, при нажатие (клик) мы отслеживаем, работем с классом (слот).
    connect(ui->pushButton_zero,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_one,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_two,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_three,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_four,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_five,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_six,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_eight,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_nine,SIGNAL(clicked()),this,SLOT(digits_numbers()));

    connect(ui->pushButton_plus_minus,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_percent,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_x_two,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_2_sq_x,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_one_x,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_bin,SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->pushButton_hex,SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->pushButton_divide,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operation()));
    connect(ui->pushButton_multiply,SIGNAL(clicked()),this,SLOT(math_operation()));

    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers() // Обработка всех нажатий. Метод (Первый, главный)
{
    //Указатель батон
    QPushButton *button=(QPushButton *)sender(); //Метод позволяет получить

    double all_numbers;
    QString new_lable,new_lable_two;
    if(ui->label->text().contains(".") && button->text() == "0"){ //Проверка, еще один 0.00
        new_lable = ui->label->text() + button->text();
    } else {
    all_numbers = (ui->label->text() + button->text()).toDouble();

    //С чилового в текстовый, вывод 15 чисел.
    new_lable = QString::number(all_numbers, 'g', 15);
    //Вывод на экран
    }
    ui->label->setText(new_lable);
}

void MainWindow::on_pushButton_dot_clicked() //Добавление точки
{
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}


void MainWindow::operations() // Обработка всех нажатий. Метод
{
    //Указатель батон
    QPushButton *button=(QPushButton *)sender(); //Метод позволяет получить

    double all_numbers, sq, hex_num;
    int64_t dec, bin, j;
    QString new_lable;

    if(button->text() == "+/-") {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * -1;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_lable);
    } else if (button->text() == "%") {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_lable);
    } else if (button->text() == "X²") {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = all_numbers * all_numbers;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_lable);
    } else if (button->text() == "2 √ x") {
        all_numbers = (ui->label->text()).toDouble();
        sq = sqrt(all_numbers);
        new_lable = QString::number(sq, 'g', 15);

        ui->label->setText(new_lable);
    } else if (button->text() == "1/x") {
        all_numbers = (ui->label->text()).toDouble();
        all_numbers = (all_numbers / all_numbers)/all_numbers;
        new_lable = QString::number(all_numbers, 'g', 15);

        ui->label->setText(new_lable);
    } else if (button->text() == "BIN") { //BIN
        all_numbers = (ui->label->text()).toDouble();


        bin = 0;
        dec = all_numbers;
        for(j=0; dec>0; j++)
        {
            bin+=(dec%2)*pow(10.0,j);
            dec/=2;
        }

        new_lable = QString::number(bin, 'g', 15);
        ui->label_2->setText(new_lable);
    } /*else if (button->text() == "HEX") {

        all_numbers = (ui->label->text()).toDouble();
        sq = sqrt(all_numbers);

        hex_num = all_numbers;
        QString codeHex = QString("%1").arg(hex_num, 0, 16);
        QString hexvalue = QString("%1").arg(hex_num, 8, 16, QLatin1Char( '0' ));
        QString hexvalue = QString("0x%1").arg(hex_num, 8, 16, QLatin1Char( '0' ));
       new_lable = QString::number(hexvalue, 'g', 15);

        ui->label_2->setText(codeHex);
}*/

}

void MainWindow::math_operation()
{
    QPushButton *button=(QPushButton *)sender();
    num_first = ui->label->text().toDouble();//Первое число помещать в переменную ферст
    ui->label->setText("");
    button->setChecked(true); //На какую кнопку было нажато

}


void MainWindow::on_pushButton_ce_clicked()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_multiply->setChecked(false);

    ui->label->setText("0");
    ui->label_2->setText("0");
}


void MainWindow::on_pushButton_equals_clicked()
{
    double lable_num, num_second;
    QString new_lable;
    num_second = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        lable_num = num_first + num_second;
        new_lable = QString::number(lable_num, 'g', 15);

        ui->label->setText(new_lable);
        ui->pushButton_plus->setChecked(false);

    } else if(ui->pushButton_minus->isChecked())
    {
        lable_num = num_first - num_second;
        new_lable = QString::number(lable_num, 'g', 15);

        ui->label->setText(new_lable);
        ui->pushButton_minus->setChecked(false);
    }else if(ui->pushButton_divide->isChecked())
    {
        if(num_second == 0)
        {
            ui->label->setText("0");
        }else
        {
            lable_num = num_first / num_second;
            new_lable = QString::number(lable_num, 'g', 15);

            ui->label->setText(new_lable);

        }
        ui->pushButton_divide->setChecked(false);

    }else if(ui->pushButton_multiply->isChecked())
    {
        lable_num = num_first * num_second;
        new_lable = QString::number(lable_num, 'g', 15);
        ui->label->setText(new_lable);
        ui->pushButton_multiply->setChecked(false);
    }
}

