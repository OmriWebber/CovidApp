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
    ur= new User_Registration(this);
    ur->show();
}


void MainWindow::on_pushButton_userLogin_clicked()
{
    hide();
    ul= new user_login(this);
    ul->show();
}


void MainWindow::on_pushButton_adminLogin_clicked()
{
    hide();
    al= new AdminLogin(this);
    al->show();
}

