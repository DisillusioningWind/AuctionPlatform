#include "TabBuyerWidget.h"

TabBuyerWidget::TabBuyerWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniSignalSlots();
}
TabBuyerWidget::~TabBuyerWidget()
{}

void TabBuyerWidget::IniUI()
{
	lb = new QLabel(QStringLiteral("�������"), this);
	lb->setProperty("UperLb", "true");
	wTab = new QTabWidget(this);
	//Init Page
	IniPageComs();
	IniPageOdrs();
	//Add Tab
	wTab->addTab(pageComs, QStringLiteral("��Ʒ"));
	wTab->addTab(pageOdrs, QStringLiteral("����"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setMargin(0);
	lay->setSpacing(0);
	lay->addWidget(lb);
	lay->addWidget(wTab);
}
void TabBuyerWidget::IniSignalSlots()
{

}

void TabBuyerWidget::IniPageComs()
{
	pageComs = new QWidget();

}
void TabBuyerWidget::IniPageOdrs()
{
	pageOdrs = new QWidget();
}