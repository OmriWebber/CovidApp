#ifndef ADMIN_PROFILE_H
#define ADMIN_PROFILE_H

#include <QDialog>

namespace Ui {
class Admin_Profile;
}

class Admin_Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Profile(QWidget *parent = nullptr);
    ~Admin_Profile();

private slots:
    void on_pushButton_users_clicked();

    void on_pushButton_userReports_clicked();

    void on_pushButton_log_clicked();

    void on_pushButton_logout_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::Admin_Profile *ui;
};

#endif // ADMIN_PROFILE_H
