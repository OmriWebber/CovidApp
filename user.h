#ifndef USER_H
#define USER_H
#include <QString>
#include <QDate>

enum VaxStatus { NoDose, FirstDose, SecondDose, FirstBooster };

class User
{
public:
    User();
    User(QString username, QString password, QString name, QString id, QString dob, QString address, QString phone, VaxStatus vstat, QString firstDoseDate, QString secondDoseDate, QString firstBoosterDate);

    void setUsername(QString username);
    QString getUsername() const;

    void setPassword(QString password);
    QString getPassword() const;

    void setName(QString name);
    QString getName() const;

    void setId(QString id);
    QString getId() const;

    void setDob(QString dob);
    QString getDob() const;

    void setAddress(QString address);
    QString getAddress() const;

    void setPhone(QString phone);
    QString getPhone() const;

    void setVaxStatus(VaxStatus vstat);
    VaxStatus getVaxStatus() const;

    void setFirstDoseDate(QString firstDoseDate);
    QString getFirstDoseDate() const;

    void setSecondDoseDate(QString secondDoseDate);
    QString getSecondDoseDate() const;

    void setFirstBoosterDate(QString firstBoosterDate);
    QString getFirstBoosterDate() const;



private:
    QString username;
    QString password;
    QString name;
    QString id;
    QString dob;
    QString address;
    QString phone;
    VaxStatus vstat;
    QString firstDoseDate;
    QString secondDoseDate;
    QString firstBoosterDate;
};

#endif // USER_H
