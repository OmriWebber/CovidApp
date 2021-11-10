#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <QDialog>
#include "user.h"

namespace Ui {
class user_profile;
}

class user_profile : public QDialog
{
    Q_OBJECT

public:
    explicit user_profile(QWidget *parent = nullptr);
    ~user_profile();

private:
    Ui::user_profile *ui;
};

#endif // USER_PROFILE_H
