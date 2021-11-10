#ifndef USER_LOGIN_H
#define USER_LOGIN_H

#include <QDialog>
#include "user.h"
#include "user_profile.h"


namespace Ui {
class user_login;
}

class user_login : public QDialog
{
    Q_OBJECT

public:
    explicit user_login(QWidget *parent = nullptr);
    ~user_login();

    User *currentUser;

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::user_login *ui;
    user_profile *up;

};

#endif // USER_LOGIN_H
