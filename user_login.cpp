#include "user_login.h"
#include "ui_user_login.h"

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
         qDebug() << data.at(0) << data.at(1) << " : " << username << password;

            if(username==data.at(0) && password==data.at(1))
            {
                msg = " You have successfully logged in!";
                hide();
                up= new user_profile(this);
                up->show();
                break;


            }
            else
            {
                msg = "Wrong username or password!";

            }
     }

     QMessageBox::information(this,"Login",msg);
}

