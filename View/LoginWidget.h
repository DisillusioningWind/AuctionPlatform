#pragma once

#include "../GlobalVariable.h"
#include "UsrWidget.h"
#include "AdminWidget.h"
#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class LoginWidget : public QWidget
{
    Q_OBJECT
private:
    //
    UsrWidget* wUsr;
    AdminWidget* wAdmin;
    //UI Widgets
    QLabel* lbTitle;
    QLabel* lbName;
    QLabel* lbPwd;
    QLineEdit* leName;
    QLineEdit* lePwd;
    QPushButton* btnUsrLogin;
    QPushButton* btnUsrRegister;
    QPushButton* btnAdminLogin;
    QPushButton* btnExit;
    //Mouse Responses
    bool mMoveState;
    QPoint mLastPos;
    //Widget Initialize
    void IniUI();
    void IniStyleSheet();
    void IniSignalSlots();
private slots:
    void btnUsrLoginClick();
    void btnUsrRegisterClick();
    void btnAdminLoginClick();
    void widgetShow();
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
    void keyPressEvent(QKeyEvent* e);
public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();
};
