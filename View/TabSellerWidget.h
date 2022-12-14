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
#include <QTextEdit>
#include <QMessageBox>
#include <QListView>
#include <QListWidget>
#include <QStringListModel>
#include <QTextBrowser>

class TabSellerWidget : public QWidget
{
	Q_OBJECT
private:
	QLabel* lb;
	QTabWidget* wTab;
	//Page
	QWidget* pageComs;
	QWidget* pageRele;
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
	QTextEdit* tbComDes;
	QRadioButton* btnComStUp;
	QRadioButton* btnComStDo;
	QPushButton* btnClo;
	QPushButton* btnBid;
	std::string cid;
	CommodityModel com;
	//Page Rele
	QLabel* lbReNam;
	QLabel* lbRePri;
	QLabel* lbReNum;
	QLabel* lbReDes;
	QLineEdit* leReNam;
	QLineEdit* leRePri;
	QLineEdit* leReNum;
	QTextEdit* teReDes;
	QPushButton* btnReRe;
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
	void IniPageRele();
	void IniPageOrds();
public slots:
	void UpdatePageComs();
	void UpdatePageOrds();
	void tabChange(int index);
	void btnReReClick();
	void listComsSelect(const QModelIndex& index);
	void listOrdsSelect(const QModelIndex& index);
	void btnCloClick();
	void btnBidClick();
public:
	TabSellerWidget(QWidget *parent = nullptr);
	~TabSellerWidget();
};
