#ifndef USER_REGISTRATION_H
#define USER_REGISTRATION_H

#include <QDialog>
#include <QUuid>
#include "user.h"

namespace Ui {
class User_Registration;
}

class User_Registration : public QDialog
{
    Q_OBJECT

public:
    explicit User_Registration(QWidget *parent = nullptr);
    ~User_Registration();

    void Register();
    QString generateID();
    VaxStatus calcVaxStatus(QDate, QDate);

private slots:
    void on_checkBox_stateChanged(int arg1);

private:
    Ui::User_Registration *ui;
};

#endif // USER_REGISTRATION_H
