#include "user.h"

User::User(QString username, QString password, QString name, QString id, QString dob, QString address, QString phone, VaxStatus vstat, QString firstDoseDate, QString secondDoseDate, QString firstBoosterDate){
    this->username = username;
    this->password = password;
    this->name = name;
    this->id = id;
    this->dob = dob;
    this->address = address;
    this->phone = phone;
    this->vstat = vstat;
    this->firstDoseDate = firstDoseDate;
    this->secondDoseDate = secondDoseDate;
    this->firstBoosterDate = firstBoosterDate;
}

void User::setName(QString name){
    this->name = name;
}

QString User::getName() const {
    return name;
}

void User::setId(QString id){
    this->id = id;
}

QString User::getId() const {
    return id;
}

void User::setDob(QString dob){
    this->dob = dob;
}

QString User::getDob() const {
    return dob;
}

void User::setAddress(QString address) {
    this->address = address;
}

QString User::getAddress() const {
    return address;
}

void User::setPhone(QString phone) {
    this->phone = phone;
}

QString User::getPhone() const {
    return phone;
}

void User::setVaxStatus(VaxStatus vstat) {
    this->vstat = vstat;
}

VaxStatus User::getVaxStatus() const {
    return vstat;
}

void User::setFirstDoseDate(QString firstDoseDate) {
    this->firstDoseDate = firstDoseDate;
}

QString User::getFirstDoseDate() const {
    return firstDoseDate;
}

void User::setSecondDoseDate(QString secondDoseDate) {
    this->secondDoseDate = secondDoseDate;
}

QString User::getSecondDoseDate() const {
    return secondDoseDate;
}

void User::setFirstBoosterDate(QString firstBoosterDate) {
    this->firstBoosterDate = firstBoosterDate;
}

QString User::getFirstBoosterDate() const {
    return firstBoosterDate;
}

