#include "admin_profile.h"
#include "ui_admin_profile.h"

#include <QWidget>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDebug>
#include <QVector>

Admin_Profile::Admin_Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_Profile)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Admin_Profile::~Admin_Profile()
{
    delete ui;
}

void Admin_Profile::on_pushButton_users_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Admin_Profile::on_pushButton_userReports_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Admin_Profile::on_pushButton_log_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void Admin_Profile::on_pushButton_logout_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}



void Admin_Profile::on_stackedWidget_currentChanged(int arg1)
{
    if(arg1 == 0) {

    } else if (arg1 == 1) {
        QFile userFile("../CS106/user.txt");
        userFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream userIn(&userFile);

        QFormLayout *layout = qobject_cast<QFormLayout*>(ui->formLayout->layout());
        layout->setVerticalSpacing(10);
        while(!userIn.atEnd())
        {
            QString line = userIn.readLine();
            QStringList data= line.split(",");

            QString name = data.at(2);
            QString id = "ID: " + data.at(3);
            QString dob = "DOB: " + data.at(4);
            QString email = "Email: " + data.at(5);
            QString phone = "Phone: " + data.at(6);
            QString vaxStatus = "Vaccination Status: " + getVaxStatus(data.at(9));

            QGridLayout *newListItem = new QGridLayout();
            newListItem->addWidget(new QLabel(name),0,0);
            newListItem->addWidget(new QLabel(id),2,0,1,2);
            newListItem->addWidget(new QLabel(dob),0,1);
            newListItem->addWidget(new QLabel(email),1,1);
            newListItem->addWidget(new QLabel(phone),0,2);
            newListItem->addWidget(new QLabel(vaxStatus),1,2);
            QPushButton *editButton = new QPushButton("Edit");
            editButton->setMinimumHeight(60);
            editButton->setMinimumWidth(80);
            editButton->setMaximumHeight(60);
            editButton->setMaximumWidth(80);
            newListItem->addWidget(editButton,0,3);
            QFrame *border = new QFrame;
            border->setMaximumHeight(2);
            border->setStyleSheet("QFrame{border: 1px solid black;}");
            newListItem->addWidget(border,3,0,1,4);


            layout->addRow(newListItem);
        }

    } else if (arg1 == 2) {

    } else if (arg1 == 3) {

    } else if (arg1 == 4) {

    } else if (arg1 == 5) {

    } else if (arg1 == 6) {

    } else if (arg1 == 7) {

    } else if (arg1 == 8) {

    } else if (arg1 == 9) {

    }
}

QString getVaxStatus(QString status){
    if(status == "0") {
        return "No Dose";
    } else if(status == "1"){
        return "First Dose";
    } else if (status == "2") {
        return "Fully Vaccinated";
    } else if (status == "3") {
        return "Fully Vaccinated + Booster" ;
    } else {
        return "No Dose";
    }
}

