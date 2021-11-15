#include "user_profile.h"
#include "ui_user_profile.h"

user_profile::user_profile(User currentUser, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_profile)
{
    ui->setupUi(this);

    // Download QR Code from API
    QUrl imageUrl("https://api.qrserver.com/v1/create-qr-code/?size=180x180&data=" + currentUser.getId());
    m_pImgCtrl = new qrdownloader(imageUrl, this);
    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));

    // Set Profile Info
    ui->user_fullname->setText(currentUser.getName());
    ui->user_address->setText(currentUser.getAddress());
    ui->user_dob->setText(currentUser.getDob());
    ui->user_phone->setText(currentUser.getPhone());

    // Hide Vaccination data by default
    ui->VaxDates->setVisible(0);
    ui->vaxEligibility->setVisible(0);
    ui->VaxDates_2->setVisible(0);
    ui->vaxEligibility_2->setVisible(0);

    // Get Vaccination Status
    VaxStatus currentVaxStatus = currentUser.getVaxStatus();

    if(currentVaxStatus == 0) {
        ui->user_vaxStatus->setText("No Dose");
    } else if (currentVaxStatus == 1) {
        ui->user_vaxStatus->setText("First Dose");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(1);

        ui->user_vaxStatus_2->setText("First Dose");
        ui->VaxDates_2->setVisible(1);
        ui->vaxEligibility_2->setVisible(1);

        QDate firstDoseDate = QDate::fromString(currentUser.getFirstDoseDate(), "dd.MM.yyyy");
        QDate eligibleSecondDoseDate = firstDoseDate.addDays(21);

        ui->label_eligibleDate->setText(eligibleSecondDoseDate.toString("dd.MM.yyyy"));
        ui->label_secondDose->setVisible(0);

        ui->label_eligibleDate_2->setText(eligibleSecondDoseDate.toString("dd.MM.yyyy"));
        ui->label_secondDose_2->setVisible(0);
    } else if (currentVaxStatus == 2) {
        ui->user_vaxStatus->setText("Fully Vaccinated");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(0);

        ui->user_vaxStatus_2->setText("Fully Vaccinated");
        ui->VaxDates_2->setVisible(1);
        ui->vaxEligibility_2->setVisible(0);
    } else if (currentVaxStatus == 3) {
        ui->user_vaxStatus->setText("Fully Vaccinated + Booster");
        ui->VaxDates->setVisible(1);
        ui->vaxEligibility->setVisible(0);

        ui->user_vaxStatus_2->setText("Fully Vaccinated + Booster");
        ui->VaxDates_2->setVisible(1);
        ui->vaxEligibility_2->setVisible(0);
    }
    ui->user_firstDoseDate->setText(currentUser.getFirstDoseDate());
    ui->user_secondDoseDate->setText(currentUser.getSecondDoseDate());

    ui->user_firstDoseDate_2->setText(currentUser.getFirstDoseDate());
    ui->user_secondDoseDate_2->setText(currentUser.getSecondDoseDate());

    // Hide Edit By Default
    ui->groupBox_edit->setVisible(0);
    ui->pushButton_finishEdit->setVisible(0);
}

user_profile::~user_profile()
{
    delete ui;
}

void user_profile::on_pushButton_finishEdit_clicked() {
    ui->groupBox_edit->setVisible(0);
    ui->pushButton_finishEdit->setVisible(0);
    ui->groupBox->setVisible(1);
    ui->pushButton_edit->setVisible(1);
}


void user_profile::on_pushButton_edit_clicked() {
    ui->groupBox->setVisible(0);
    ui->pushButton_edit->setVisible(0);
    ui->groupBox_edit->setVisible(1);
    ui->pushButton_finishEdit->setVisible(1);
}


void user_profile::on_pushButton_logout_clicked() {
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

// Load QR Code into label
void user_profile::loadImage() {
    QPixmap qrCodeImage;
    qrCodeImage.loadFromData(m_pImgCtrl->downloadedData());
    ui->label_qrcode->setPixmap(qrCodeImage);
    ui->label_qrcode_2->setPixmap(qrCodeImage);
}


// Add report issues section




void user_profile::on_pushButton_Book_clicked()
{
    QDesktopServices::openUrl(QUrl("https://bookmyvaccine.covid19.health.nz/", QUrl::TolerantMode));
}


void user_profile::on_pushButton_3_clicked()
{
    QDesktopServices::openUrl(QUrl("https://www.healthpoint.co.nz/covid-19/", QUrl::TolerantMode));
}

