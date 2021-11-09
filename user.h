#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>

enum VaxStatus { NoDose, FirstDose, SecondDose, FirstBooster };

class User
{
public:
    User(QString username, QString password, QString name, QString id, QDate dob, QString address, QString phone, VaxStatus vstat, QDate firstDoseDate, QDate secondDoseDate, QDate firstBoosterDate);

    void setUsername(QString username);
    QString getUsername() const;

    void setPassword(QString password);
    QString getPassword() const;

    void setName(QString name);
    QString getName() const;

    void setId(QString id);
    QString getId() const;

    void setDob(QDate dob);
    QDate getDob() const;

    void setAddress(QString address);
    QString getAddress() const;

    void setPhone(QString phone);
    QString getPhone() const;

    void setVaxStatus(VaxStatus vstat);
    VaxStatus setVaxStatus() const;

    void setFirstDoseDate(QDate firstDoseDate);
    QDate getFirstDoseDate() const;

    void setSecondDoseDate(QDate secondDoseDate);
    QDate getSecondDoseDate() const;

    void setFirstBoosterDate(QDate firstBoosterDate);
    QDate getFirstBoosterDate() const;



private:
    QString username;
    QString password;
    QString name;
    QString id;
    QDate dob;
    QString address;
    QString phone;
    VaxStatus vstat;
    QDate firstDoseDate;
    QDate secondDoseDate;
    QDate firstBoosterDate;
};

#endif // USER_H
