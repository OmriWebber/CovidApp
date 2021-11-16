#include "user_test_record.h"
#include "ui_user_test_record.h"

#include <QFile>
#include <QMessageBox>

user_testRecord::user_testRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::user_testRecord)
{
    ui->setupUi(this);
    QFile recFile("../CS106/testRecord.txt");
    if(!recFile.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"File","File is not open");
    }
    QTextStream in(&recFile);
    QString rdata= in.readAll();
    ui->plainTextEdit_testRecord->setPlainText(rdata);
    recFile.close();
}

user_testRecord::~user_testRecord()
{
    delete ui;
}

void user_testRecord::on_pushButton_back_clicked()
{
    this->hide();
    QWidget *parent = this->parentWidget();
    parent->show();
}


void user_testRecord::on_pushButton_refresh_clicked()
{
    QFile recFile("../CS106/testRecord.txt");
    if(!recFile.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,"File","File is not open");
    }
    QTextStream in(&recFile);
    QString rdata= in.readAll();
    ui->plainTextEdit_testRecord->setPlainText(rdata);
    recFile.close();
    QMessageBox::about(this,"Refresh","Your Covid Testing Record has been updated");
}

