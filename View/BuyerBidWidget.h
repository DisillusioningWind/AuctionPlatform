#pragma once

#include "../GlobalVariable.h"
#include <QDialog>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

class BuyerBidWidget : public QDialog
{
	Q_OBJECT

public:
	BuyerBidWidget(std::string cid, QWidget *parent = nullptr);
	~BuyerBidWidget();

	QLabel* lbOff;
	QLabel* lbNum;
	QLineEdit* leOff;
	QLineEdit* leNum;
	QPushButton* btnBBid;
	std::string cid;

	void IniUI();
	void IniSignalSlots();
public slots:
	void btnBBidClick();
};
