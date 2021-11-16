#ifndef USER_REPORT_H
#define USER_REPORT_H

#include <QDialog>

namespace Ui {
class user_report;
}

class user_report : public QDialog
{
    Q_OBJECT

public:
    explicit user_report(QWidget *parent = nullptr);
    ~user_report();

private slots:
    void on_pushButton_back_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_submit_clicked();

private:
    Ui::user_report *ui;
};

#endif // USER_REPORT_H
