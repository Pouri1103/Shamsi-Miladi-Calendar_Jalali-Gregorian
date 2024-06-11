#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QCalendar>
#include <QString>
#include <QDate>

//--------------------------

QString Type = "miladi";

//--------------------------

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


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::setLocation(QString type)
{
    QCalendar jalali(QCalendar::System::Jalali);
    QCalendar global(QCalendar::System::Gregorian);
    QLocale iranLocale(QLocale::Persian,QLocale::Iran);
    QLocale globalLocale(QLocale::English,QLocale::UnitedStates);

    if (type == "shamsi")
    {
        ui->calendarWidget->setCalendar(jalali);
        ui->calendarWidget->setLocale(iranLocale);
        ui->calendarWidget->setFont(QFont("B homa",13));
    }
    else if (type == "miladi")
    {
        ui->calendarWidget->setCalendar(global);
        ui->calendarWidget->setLocale(globalLocale);
        ui->calendarWidget->setFont(QFont("Dosis ExtraBold",13,QFont::Bold));
    }
    Type = type;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    QCalendar convert(QCalendar::System::Jalali);
    QString jalali = date.toString("yyyy/MM/dd",convert);

    if (Type == "shamsi")
        ui->lineEdit->setText(jalali);
    else
        ui->lineEdit->setText(date.toString("yyyy/MM/dd"));

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_comboBox_activated(int index)
{
    if (index == 0)
        setLocation("miladi");
    else if (index == 1)
        setLocation("shamsi");
}

