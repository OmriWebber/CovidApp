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
    hide();
    User *newUser;
    ur= new User_Registration(newUser, this);
    ur->show();
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

