#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_userRegistration_clicked()
{

}


void MainWindow::on_pushButton_userLogin_clicked()
{

}


void MainWindow::on_pushButton_adminLogin_clicked()
{
    hide();
    al= new AdminLogin(this);
    al->show();
}

