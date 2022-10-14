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

class TabBuyerWidget : public QWidget
{
	Q_OBJECT
private:
	QLabel* lb;
	QTabWidget* wTab;
	//Page
	QWidget* pageComs;
	QWidget* pageOdrs;
	//Widget Initialize
	void IniUI();
	void IniSignalSlots();
	void IniPageComs();
	void IniPageOdrs();
public:
	TabBuyerWidget(QWidget *parent = nullptr);
	~TabBuyerWidget();
};
