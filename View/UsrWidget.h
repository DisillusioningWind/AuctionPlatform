#pragma once

#include "../GlobalVariable.h"
#include "TabUsrWidget.h"
#include "TabBuyerWidget.h"
#include "TabSellerWidget.h"
#include <QWidget>
#include <QRadioButton>
#include <QLayout>
#include <QStackedLayout>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>

class UsrWidget : public QWidget
{
	Q_OBJECT
public:
	//UI Widgets
	QRadioButton* btnUsr;
	QRadioButton* btnBuyer;
	QRadioButton* btnSeller;
	QStackedLayout* contentLay;
	TabUsrWidget* wUsr;
	TabBuyerWidget* wBuyer;
	TabSellerWidget* wSeller;
	//Widget Initialize
	void IniUI();
	void IniStyleSheet();
	void IniSignalSlots();
private slots:
	void btnRadioClick(bool checked);
	void btnLogoutClick();
public:
	UsrWidget(QWidget *parent = nullptr);
	~UsrWidget();
signals:
	void UsrWidgetClosed();
};
