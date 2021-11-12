#include "user_profile.h"
#include "ui_user_profile.h"

user_profile::user_profile(User currentUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_profile)
{
    ui->setupUi(this);

    ui->user_fullname->setText(currentUser.getName());
    ui->user_address->setText(currentUser.getAddress());
    ui->user_dob->setText(currentUser.getDob());
    ui->user_phone->setText(currentUser.getPhone());

    ui->VaxDates->setVisible(0);
    ui->vaxEligibility->setVisible(0);

    VaxStatus currentVaxStatus = currentUser.getVaxStatus();
    if(currentVaxStatus == 0) {
        ui->user_vaxStatus->setText("No Dose");
    } else if (currentVaxStatus == 1) {
        ui->user_vaxStatus->setText("First Dose");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(1);
        QDate firstDoseDate = QDate::fromString(currentUser.getFirstDoseDate(), "dd.MM.yyyy");
        QDate eligibleSecondDoseDate = firstDoseDate.addDays(21);
        ui->label_eligibleDate->setText(eligibleSecondDoseDate.toString("dd.MM.yyyy"));
        ui->label_secondDose->setVisible(0);
        qDebug() << firstDoseDate << eligibleSecondDoseDate;
    } else if (currentVaxStatus == 2) {
        ui->user_vaxStatus->setText("Fully Vaccinated");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(0);
    } else if (currentVaxStatus == 3) {
        ui->user_vaxStatus->setText("Fully Vaccinated + Booster");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(0);
    }
    ui->user_firstDoseDate->setText(currentUser.getFirstDoseDate());
    ui->user_secondDoseDate->setText(currentUser.getSecondDoseDate());
}

user_profile::~user_profile()
{
    delete ui;
}



