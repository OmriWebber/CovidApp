#include "user_profile.h"
#include "ui_user_profile.h"

user_profile::user_profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_profile)
{
    ui->setupUi(this);
}

user_profile::~user_profile()
{
    delete ui;
}
