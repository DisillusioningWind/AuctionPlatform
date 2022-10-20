#pragma once

#include "../GlobalVariable.h"
#include <QWidget>
#include <QTabWidget>
#include <QRadioButton>
#include <QPushBUtton>
#include <QLayout>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QListView>
#include <QListWidget>
#include <QStringListModel>
#include <QLineEdit>
#include <QSpacerItem>

class AdminWidget : public QWidget
{
	Q_OBJECT
private:
    QPushButton* btnLogout;
	QTabWidget* wTab;
	//Page
	QWidget* pageUsrs;
	QWidget* pageComs;
	QWidget* pageOrds;
	//Page Usrs
	QStringListModel* usrsModel;
	QListView* usrsList;
	QWidget* usrsDetWidget;
	QLabel* lbUsrUid;
	QLabel* lbUsrNam;
	QLabel* lbUsrPwd;
	QLabel* lbUsrPhn;
	QLabel* lbUsrAdd;
	QLabel* lbUsrBal;
	QLabel* lbDesUid;
	QLabel* lbDesNam;
	QLabel* lbDesPwd;
	QLabel* lbDesPhn;
	QLabel* lbDesAdd;
	QLabel* lbDesBal;
	QRadioButton* btnUsrStUp;
	QRadioButton* btnUsrStDo;
	QPushButton* btnUsrClo;
	QPushButton* btnUsrCha;
	std::string uid;
	UserModel usr;
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
	QPushButton* btnComClo;
	QPushButton* btnComCha;
	std::string cid;
	CommodityModel com;
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
	void IniStyleSheet();
	void IniSignalSlots();
	//Page Initialize
	void IniPageUsrs();
	void IniPageComs();
	void IniPageOrds();
public slots:
	void updatePageUsrs();
	void updatePageComs();
	void updatePageOrds();
	void btnLogoutClick();
	void btnComCloClick();
	void btnComChaClick();
	void btnUsrCloClick();
	void btnUsrChaClick();
	void listUsrsSelect(const QModelIndex& index);
	void listComsSelect(const QModelIndex& index);
	void listOrdsSelect(const QModelIndex& index);
public:
	AdminWidget(QWidget *parent = nullptr);
	~AdminWidget();
signals:
	void AdminWidgetClosed();
};
