#include "TabSellerWidget.h"

TabSellerWidget::TabSellerWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniSignalSlots();
}
TabSellerWidget::~TabSellerWidget()
{}

void TabSellerWidget::IniUI()
{
	lb = new QLabel(QStringLiteral("��������"), this);
	lb->setProperty("UperLb", "true");
	wTab = new QTabWidget(this);
	//Page
	pageComs = new QWidget();
	pageRele = new QWidget();
	//
	QLabel* a = new QLabel("coms");
	QLabel* b = new QLabel("com");
	a->setParent(pageComs);
	b->setParent(pageRele);
	//Add Tab
	wTab->addTab(pageComs, QStringLiteral("��Ʒ"));
	wTab->addTab(pageRele, QStringLiteral("����"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setMargin(0);
	lay->setSpacing(0);
	lay->addWidget(lb);
	lay->addWidget(wTab);
}
void TabSellerWidget::IniSignalSlots()
{

}