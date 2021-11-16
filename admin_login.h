#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>
#include "admin_profile.h"

namespace Ui {
class AdminLogin;
}

class AdminLogin : public QDialog
{
    Q_OBJECT

public:
    explicit AdminLogin(QWidget *parent = nullptr);
    ~AdminLogin();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_goback_clicked();

private:
    Ui::AdminLogin *ui;
    Admin_Profile *ap;
};

#endif // ADMIN_LOGIN_H
