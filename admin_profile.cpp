#include "admin_profile.h"
#include "ui_admin_profile.h"

Admin_Profile::Admin_Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_Profile)
{
    ui->setupUi(this);
}

Admin_Profile::~Admin_Profile()
{
    delete ui;
}
