QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_login.cpp \
    admin_profile.cpp \
    main.cpp \
    mainwindow.cpp \
    qrdownloader.cpp \
    user.cpp \
    user_login.cpp \
    user_profile.cpp \
    user_registration.cpp \
    user_report.cpp \
    user_test_record.cpp

HEADERS += \
    admin_login.h \
    admin_profile.h \
    mainwindow.h \
    qrdownloader.h \
    user.h \
    user_login.h \
    user_profile.h \
    user_registration.h \
    user_report.h \
    user_test_record.h

FORMS += \
    admin_login.ui \
    admin_profile.ui \
    mainwindow.ui \
    user_login.ui \
    user_profile.ui \
    user_registration.ui \
    user_report.ui \
    user_test_record.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    admin.txt \
    log.txt \
    reportFile.txt \
    testRecord.txt \
    user.txt
