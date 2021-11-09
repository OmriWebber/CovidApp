#include "user_registration.h"
#include "ui_user_registration.h"

#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QUuid>
#include <QRandomGenerator>
#include <QDebug>

User_Registration::User_Registration(User*& newUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_Registration)
{
    ui->setupUi(this);
    this->newUser = &newUser;
    ui->vaxStatus_box->setVisible(0);

    //registering the events
    connect(ui->btnRegister, &QPushButton::clicked,
            this, &User_Registration::Register);
}

User_Registration::~User_Registration()
{
    delete ui;
}

void User_Registration::Register()
{
    QString username = ui->input_username->text();
    QString password = ui->input_password->text();
    QString fullname = ui->input_fullname->text();
    QString Id = generateID();
    QDate DOB = QDate(ui->input_dob_day->text().toInt(), ui->input_dob_month->text().toInt(), ui->input_dob_year->text().toInt());
    QString Address = ui->input_address->text();
    QString Phone = ui->input_phone->text();
    QDate firstDose = QDate(ui->input_dob_day_2->text().toInt(), ui->input_dob_month_2->text().toInt(), ui->input_dob_year_2->text().toInt());
    QDate secondDose = QDate(ui->input_dob_day_3->text().toInt(), ui->input_dob_month_3->text().toInt(), ui->input_dob_year_3->text().toInt());
    VaxStatus vStat = calcVaxStatus(firstDose, secondDose);
    QDate firstBoosterDate;


    QFile userFile("out.txt");
    if(userFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
        QTextStream out(&userFile);
        out<<username<<",";
        out<<password<<",";
        out<<fullname<<",";
        out<<Id<<",";
        out<<DOB.toString("dd/MM/yyyy")<<",";
        out<<Address<<",";
        out<<Phone<<",";
        out<<firstDose.toString("dd/MM/yyyy")<<",";
        out<<secondDose.toString("dd/MM/yyyy")<<",";
        out<<vStat<<",";
        out<<firstBoosterDate.toString("dd/MM/yyyy")<<Qt::endl;
        qDebug() << DOB.toString("dd/MM/yyyy");
    }




   /*

   */

}//end confirmAdd


QString User_Registration::generateID(){
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
       const int randomStringLength = 64; // assuming you want random strings of 12 characters

       QString randomString;
       for(int i=0; i<randomStringLength; ++i)
       {
           int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
           QChar nextChar = possibleCharacters.at(index);
           randomString.append(nextChar);
       }
       return randomString;
}

void User_Registration::on_checkBox_stateChanged(int arg1)
{
    qDebug() << arg1;
    if(arg1 == 0){
        ui->vaxStatus_box->setVisible(0);
    } else if(arg1 == 2){
        ui->vaxStatus_box->setVisible(1);
    }
}


VaxStatus User_Registration::calcVaxStatus(QDate firstDose, QDate secondDose){
    if(firstDose.isValid() && secondDose.isValid()) {
        return SecondDose;
    } else if(firstDose.isValid()) {
        return FirstDose;
    } else {
        return NoDose;
    }
}

