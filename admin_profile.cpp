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
        QTextStream in(&userFile);

        QFormLayout *layout = qobject_cast<QFormLayout*>(ui->formLayout->layout());
        QVector<QFrame> userList;
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data= line.split(",");

            QString name = data.at(3);


            QFrame *newListItem = new QFrame(ui->listItem_template);
            layout->addRow(newListItem);
            qDebug() << newListItem->children().count();
        }

        for (int i = 0; i < userList.count(); i++) {

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

