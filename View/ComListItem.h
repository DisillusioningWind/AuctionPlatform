#pragma once

#include <QWidget>
#include <QLabel>
#include <QLayout>

class ComListItem : public QWidget
{
	Q_OBJECT

public:
	ComListItem(std::string cid, std::string nam, std::string pri, std::string num, std::string des, QWidget *parent = nullptr);
	~ComListItem();

	QLabel* lbCid;
	QLabel* lbNam;
	QLabel* lbPri;
	QLabel* lbNum;
	QLabel* lbDes;
};
