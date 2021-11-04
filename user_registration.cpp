#include "user_registration.h"
#include "ui_user_registration.h"

#include <QDir>
#include <QMessageBox>
#include <QFileDialog>

User_Registration::User_Registration(User*& newUser, QWidget *parent) :
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

void User_Registration::confirmAdd()
{
    QString productName = ui->txtProductName->text();
    int quantity = ui->sbQuantity->value();

    if (productName.trimmed() != "" && quantity >= 1)
    {
        *newUser = new User ();
        this->close();
    }
    else
    {
        QMessageBox mb;
        mb.setText("You must have a valid name and a quantity of at least 1");
        mb.exec();

    }
}//end confirmAdd


void User_Registration::loadItemImage()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Open Image", "./",
                                            "Image Files (*.png *.jpg)");

    if (filename != "")
    {
        int lastSlash = filename.lastIndexOf("/");

        QString shortName = filename.right(filename.size() - lastSlash - 1);

        QFile::copy(filename, "./images/" + shortName);

        QPixmap pixmap("./images/" + shortName);

        ui->lblImage->setPixmap(pixmap);
        ui->lblImage->setScaledContents(true);

        imageFilePath = "./images/" + shortName;

    }

} //end load item image
