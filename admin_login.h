#ifndef ADMIN_LOGIN_H
#define ADMIN_LOGIN_H

#include <QDialog>

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

private:
    Ui::AdminLogin *ui;
};

#endif // ADMIN_LOGIN_H