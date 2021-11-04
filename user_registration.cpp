#include "user_registration.h"
#include "ui_user_registration.h"

#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

User_Registration::User_Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_Registration)
{
    ui->setupUi(this);
    this->newUser = &newUser;
    imageFilePath = "none.png"; //default

    //registering the events
    connect(ui->btnConfirmAdd, &QPushButton::clicked,
            this, &User_Registration::confirmAdd);

    connect(ui->btnLoadImage, &QPushButton::clicked,
            this, &User_Registration::loadItemImage);

    QDir pathDir("./images");
    if(!pathDir.exists())
    {
        //create it!
        QDir().mkdir("./images");
    }
}

User_Registration::~User_Registration()
{
    delete ui;
}
