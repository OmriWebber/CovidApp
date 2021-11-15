#ifndef USER_PROFILE_H
#define USER_PROFILE_H

#include <QDialog>
#include "user.h"

#include "qrdownloader.h"
#include <QUrl>
#include <QDesktopServices>

namespace Ui {
class user_profile;
}

class user_profile : public QDialog
{
    Q_OBJECT

public:
    explicit user_profile(User currentUser, QWidget *parent = nullptr);
    ~user_profile();

private slots:

    void on_pushButton_finishEdit_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_logout_clicked();

    void loadImage();



    void on_pushButton_Book_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::user_profile *ui;
    qrdownloader *m_pImgCtrl;
};

#endif // USER_PROFILE_H
