#include "ComListItem.h"

ComListItem::ComListItem(std::string cid, std::string nam, std::string pri, std::string num, std::string des, QWidget *parent) : QWidget(parent)
{
	lbCid = new QLabel(QString::fromStdString(cid), this);
	lbNam = new QLabel(QString::fromStdString(nam), this);
	lbPri = new QLabel(QString::fromStdString(pri), this);
	lbNum = new QLabel(QString::fromStdString(num), this);
	lbDes = new QLabel(QString::fromStdString(des), this);

	QGridLayout* lay = new QGridLayout(this);
	lay->addWidget(lbCid, 1, 1, 1, 3);
	lay->addWidget(lbNam, 2, 1, 1, 1);
	lay->addWidget(lbPri, 2, 2, 1, 1);
	lay->addWidget(lbNum, 2, 3, 1, 1);
	lay->addWidget(lbDes, 3, 1, 1, 3);
}
ComListItem::~ComListItem()
{}
