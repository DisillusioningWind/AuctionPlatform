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
	lb = new QLabel(QStringLiteral("我是卖家"), this);
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
	wTab->addTab(pageComs, QStringLiteral("商品"));
	wTab->addTab(pageRele, QStringLiteral("发布"));
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