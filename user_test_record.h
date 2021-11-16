#ifndef USER_TEST_RECORD_H
#define USER_TEST_RECORD_H

#include <QDialog>

namespace Ui {
class user_testRecord;
}

class user_testRecord : public QDialog
{
    Q_OBJECT

public:
    explicit user_testRecord(QWidget *parent = nullptr);
    ~user_testRecord();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::user_testRecord *ui;
};

#endif // USER_TEST_RECORD_H
