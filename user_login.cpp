#include "user_login.h"
#include "ui_user_login.h"
#include "user.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>

user_login::user_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_login)
{
    ui->setupUi(this);
}

user_login::~user_login()
{
    delete ui;
}

void user_login::on_pushButton_login_clicked()
{
    QString username = ui->input_username->text();
    QString password= ui->input_password->text();
    QString msg;

    //~~~~~~File code starts~~~~~~~~~~~~
     QFile userFile("../CS106/user.txt");
     userFile.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&userFile);
     //~~~~~~File code ends~~~~~~~~~~~~

     while(!in.atEnd())
     {
         QString line = in.readLine();
         QStringList data= line.split(",");

            if(username==data.at(0) && password==data.at(1))
            {
                User currentUser(data.at(0),data.at(1),data.at(2),data.at(3),data.at(4),data.at(5),data.at(6),convertStringToVaxStatus(data.at(9)),data.at(7),data.at(8),data.at(10));
                msg = " You have successfully logged in!";
                hide();
                up= new user_profile(currentUser, this);
                up->show();
                break;


            }
            else
            {
                msg = "Wrong username or password!";

            }
     }
}

VaxStatus convertStringToVaxStatus(QString status){
    if(status == "0") {
        return NoDose;
    } else if(status == "1"){
        return FirstDose;
    } else if (status == "2") {
        return SecondDose;
    } else if (status == "3") {
        return FirstBooster;
    } else {
        return NoDose;
    }
}


void user_login::on_pushButton_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

