#include "admin_login.h"
#include "ui_admin_login.h"

#include <QMessageBox>

#include <QFile>
#include <QTextStream>
#include <QString>
AdminLogin::AdminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminLogin)
{
    ui->setupUi(this);
}

AdminLogin::~AdminLogin()
{
    delete ui;
}

void AdminLogin::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password= ui->lineEdit_password->text();
    QString msg;

    //~~~~~~File code starts~~~~~~~~~~~~
     QFile userFile("../CS106/admin.txt");
     userFile.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream in(&userFile);
     //~~~~~~File code ends~~~~~~~~~~~~

     while(!in.atEnd())
     {
         QString line = in.readLine();
         QStringList data= line.split(",");

            if(username==data.at(0) && password==data.at(1))
            {
                msg = " You have successfully logged in!";

                QDateTime currentTime = QDateTime::currentDateTime();
                QFile logFile("../CS106/log.txt");
                if(logFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
                    QTextStream log(&logFile);
                    log<<currentTime.toString()<<" " << username << " logged in as an admin";
                }

                hide();
                ap= new Admin_Profile(this);
                ap->show();
                break;
            }
            else
            {
                msg = "Wrong username or password!";
            }
     }
}


void AdminLogin::on_pushButton_goback_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

