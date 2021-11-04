#ifndef USER_REGISTRATION_H
#define USER_REGISTRATION_H

#include <QDialog>
#include "user.h"

namespace Ui {
class User_Registration;
}

class User_Registration : public QDialog
{
    Q_OBJECT

public:
    explicit User_Registration(User*& newUser, QWidget *parent = nullptr);
    ~User_Registration();

    void confirmAdd();
    void loadItemImage();

private:
    Ui::User_Registration *ui;
    User** newUser;
    QString imageFilePath;
};

#endif // USER_REGISTRATION_H
