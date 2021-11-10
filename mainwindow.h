#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "user_login.h"
#include "admin_login.h"
#include "user_registration.h"
#include "user.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_userRegistration_clicked();

    void on_pushButton_userLogin_clicked();

    void on_pushButton_adminLogin_clicked();

private:
    Ui::MainWindow *ui;
    AdminLogin *al;
    User_Registration *ur;
    user_login *ul;
};
#endif // MAINWINDOW_H
