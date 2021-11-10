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

private:
    Ui::Admin_Profile *ui;
};

#endif // ADMIN_PROFILE_H
