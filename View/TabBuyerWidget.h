#pragma once

#include "../GlobalVariable.h"
#include "BuyerBidWidget.h"
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
#include <QListView>
#include <QListWidget>
#include <QStringListModel>
#include <QTextBrowser>

class TabBuyerWidget : public QWidget
{
	Q_OBJECT
private:
	QLabel* lb;
	QTabWidget* wTab;
	//Page
	QWidget* pageComs;
	QWidget* pageSech;
	QWidget* pageBids;
	QWidget* pageOrds;
	//Page Coms
	QStringListModel* comsModel;
	QListView* comsList;
	QWidget* comsDetWidget;
	QLabel* lbComNam;
	QLabel* lbComPri;
	QLabel* lbComNum;
	QLabel* lbComDes;
	QLineEdit* leComNam;
	QLineEdit* leComPri;
	QLineEdit* leComNum;
	QTextBrowser* tbComDes;
	QPushButton* btnClo;
	QPushButton* btnBid;
	std::string cid;
	CommodityModel com;
	//Page Sech
	QLineEdit* leSech;
	QPushButton* btnSech;
	QPushButton* btnClea;
	QListWidget* sechList;
	//Page Bid
	QStringListModel* bidsModel;
	QListView* bidsList;
	QWidget* bidsDetWidget;
	QLabel* lbBidCid;
	QLabel* lbBidNam;
	QLabel* lbBidPri;
	QLabel* lbBidNum;
	QLineEdit* leBidCid;
	QLineEdit* leBidNam;
	QLineEdit* leBidPri;
	QLineEdit* leBidNum;
	QPushButton* btnBidClo;
	QPushButton* btnBidCha;
	QPushButton* btnBidCan;
	map<string, vector<UserBidModel>> bids;
	//Page Ords
	QStringListModel* ordsModel;
	QListView* ordsList;
	QWidget* ordsDetWidget;
	QLabel* lbOrdOidDes;
	QLabel* lbOrdCidDes;
	QLabel* lbOrdSidDes;
	QLabel* lbOrdBidDes;
	QLabel* lbOrdPriDes;
	QLabel* lbOrdNumDes;
	QLabel* lbOrdDatDes;
	QLabel* lbOrdOid;
	QLabel* lbOrdCid;
	QLabel* lbOrdPri;
	QLabel* lbOrdNum;
	QLabel* lbOrdDat;
	QLabel* lbOrdSid;
	QLabel* lbOrdBid;
	std::string oid;
	OrderModel ord;
	//Widget Initialize
	void IniUI();
	void IniSignalSlots();
	void IniPageComs();
	void IniPageSech();
	void IniPageBids();
	void IniPageOrds();
public slots:
	void tabChange(int index);
	void listComsSelect(const QModelIndex& index);
	void listBidsSelect(const QModelIndex& index);
	void listOrdsSelect(const QModelIndex& index);
	void btnCloClick();
	void btnBidClick();
	void btnBidCloClick();
	void btnBidChaClick();
	void btnBidCanClick();
	void updatePageComs();
	void updatePageSech();
	void updatePageBids();
	void updatePageOrds();
	void clearPageSech();
public:
	TabBuyerWidget(QWidget *parent = nullptr);
	~TabBuyerWidget();
};