#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <QDialog>
#include "user.h"
#include "user_profile.h"

VaxStatus convertStringToVaxStatus(QString status);

namespace Ui {
class user_login;
}

class user_login : public QDialog
{
    Q_OBJECT

public:
    explicit user_login(QWidget *parent = nullptr);
    ~user_login();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_clicked();

private:
    Ui::user_login *ui;
    user_profile *up;

};

#endif // USER_LOGIN_H
