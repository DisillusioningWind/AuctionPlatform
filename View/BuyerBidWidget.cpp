#include "BuyerBidWidget.h"

BuyerBidWidget::BuyerBidWidget(std::string cid, QWidget *parent) : QDialog(parent)
{
	this->cid = cid;
	IniUI();
	IniSignalSlots();
}
BuyerBidWidget::~BuyerBidWidget()
{}

void BuyerBidWidget::IniUI()
{
	//Other
	lbOff = new QLabel(QStringLiteral("竞拍单价"), this);
	lbNum = new QLabel(QStringLiteral("竞拍数量"), this);
	leOff = new QLineEdit(this);
	leNum = new QLineEdit(this);
	btnBBid = new QPushButton(QStringLiteral("确认"), this);
	//Layout
	QVBoxLayout* bidLay = new QVBoxLayout(this);

	bidLay->setMargin(20);
	bidLay->setSpacing(10);

	bidLay->addWidget(lbOff);
	bidLay->addWidget(leOff);
	bidLay->addWidget(lbNum);
	bidLay->addWidget(leNum);
	bidLay->addWidget(btnBBid);
}
void BuyerBidWidget::IniSignalSlots()
{
	connect(btnBBid, SIGNAL(clicked()), this, SLOT(btnBBidClick()));
}

void BuyerBidWidget::btnBBidClick()
{
	double offer = leOff->text().toDouble();
	int num = leNum->text().toInt();
	if (pCon.BuyerBidCommodity(offer, cid, num))
	{
		QMessageBox::information(this, QStringLiteral("竞拍结果"), QStringLiteral("竞拍成功"));
		this->close();
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("竞拍结果"), QStringLiteral("竞拍失败"));
	}
}