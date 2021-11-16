#include "user_report.h"
#include "ui_user_report.h"

#include <QString>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

user_report::user_report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_report)
{
    ui->setupUi(this);
}

user_report::~user_report()
{
    delete ui;
}

void user_report::on_pushButton_back_clicked() // back fn
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

void user_report::on_pushButton_clear_clicked() // clear textEdit fn
{
    ui->plainTextEdit_report->clear();
}

void user_report::on_pushButton_submit_clicked() // submit textEdit to report file
{
    QString report = ui->plainTextEdit_report->toPlainText(); // storing textEdit to string var

    if(report=="") // checking report submit is NOT blank
    {
        QMessageBox::warning(this, "Invalid Input", "Please ensure you add a description before submitting"); // displaying 'blank' warning message
    }
    else // File handling
    {
        QFile reportFile("../CS106/reportFile.txt"); // file instance creation

        if(!reportFile.open(QFile::WriteOnly|QFile::Text|QFile::Append)) // checking file is open prior to write attempt
        {
            QMessageBox::warning(this,"Report File Issue","Report cannot be submitted, try again later."); // displaying 'not open' warning message
        }

        QTextStream out(&reportFile); // passing file obj by reference
        out<<report<<" , "; // writing string obj to file --space comma space separation
        reportFile.flush(); // flushing buffer
        reportFile.close(); // closing file after handling
        QMessageBox::information(this, "Success", "Report has been submitted successfully"); // display 'successfule file write' message
    }

    // returning user to main window (user profile in CS106)
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}

