#pragma once

#include "../GlobalVariable.h"
#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QLayout>
#include <QVariant>
#include <QLineEdit>
#include <QSpacerItem>
#include <QPushButton>
#include <QRadioButton>
#include <QStyle>
#include <QDebug>
#include <QMessageBox>

class TabUsrWidget : public QWidget
{
	Q_OBJECT
public:
	QLabel* lb;
	QTabWidget* wTab;
	//Page Widget
	QWidget* pageInfo;
	QWidget* pageChar;
	//Page Info
	QLabel* lbName;
	QLabel* lbPwd;
	QLabel* lbPh;
	QLabel* lbAdd;
	QLabel* lbBal;
	QLineEdit* leName;
	QLineEdit* lePwd;
	QLineEdit* lePh;
	QLineEdit* leAdd;
	QLineEdit* leBal;
	QPushButton* btnInfoChange;
	QPushButton* btnInfoLogout;
	//Page Charge
	QLabel* lbBalDes;
	QLabel* lbBalChar;
	QRadioButton* btnTen;
	QRadioButton* btnTew;
	QRadioButton* btnFif;
	QRadioButton* btnHun;
	QRadioButton* btnTHu;
	QRadioButton* btnCus;
	QPushButton* btnChar;
	QLineEdit* leChar;
	//Widget Initialize
	void IniUI();
	void IniSignalSlots();
	void IniPageInfo();
	void IniPageCharge();
public slots:
	void tabChange(int index);
	void btnInfoChangeClick();
	void btnInfoChangeState();
	//void btnInfoLogoutClick();
	void btnCharClick();
	void btnBalClick();
	void updatePageInfo();
	void updatePageChar();
public:
	TabUsrWidget(QWidget *parent = nullptr);
	~TabUsrWidget();
};
