#pragma once

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QMouseEvent>
#include <QDebug>
#include <QFile>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class LoginWidget : public QDialog
{
    Q_OBJECT
private:
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
protected:
    void mousePressEvent(QMouseEvent* e);
    void mouseMoveEvent(QMouseEvent* e);
    void mouseReleaseEvent(QMouseEvent* e);
public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();
};
