#pragma once

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel* lbTitle;
    QLabel* lbName;
    QLabel* lbPwd;
    QLineEdit* leName;
    QLineEdit* lePwd;
    QPushButton* btnUsrLogin;
    QPushButton* btnUsrRegister;
    QPushButton* btnAdminLogin;
    QPushButton* btnExit;

    void iniUI();
    void iniStyleSheet();
    void iniSignalSlots();
public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();
};
