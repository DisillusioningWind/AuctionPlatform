#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QLabel>
#include <QLayout>
#include <QVariant>

class TabSellerWidget : public QWidget
{
	Q_OBJECT
private:
	QLabel* lb;
	QTabWidget* wTab;
	//Page
	QWidget* pageComs;
	QWidget* pageRele;
	//Widget Initialize
	void IniUI();
	void IniSignalSlots();
public:
	TabSellerWidget(QWidget *parent = nullptr);
	~TabSellerWidget();
};
