#include "TabBuyerWidget.h"

TabBuyerWidget::TabBuyerWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniSignalSlots();
}
TabBuyerWidget::~TabBuyerWidget()
{}

void TabBuyerWidget::IniUI()
{
	lb = new QLabel(QStringLiteral("我是买家"), this);
	lb->setProperty("UperLb", "true");
	wTab = new QTabWidget(this);
	//Init Page
	IniPageComs();
	IniPageSech();
	IniPageBids();
	IniPageOrds();
	//Add Tab
	wTab->addTab(pageComs, QStringLiteral("商品"));
	wTab->addTab(pageSech, QStringLiteral("搜索"));
	wTab->addTab(pageBids, QStringLiteral("竞单"));
	wTab->addTab(pageOrds, QStringLiteral("订单"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setMargin(0);
	lay->setSpacing(0);
	lay->addWidget(lb);
	lay->addWidget(wTab);
}
void TabBuyerWidget::IniSignalSlots()
{
	connect(comsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listComsSelect(const QModelIndex)));
	connect(ordsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listOrdsSelect(const QModelIndex)));
	connect(bidsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listBidsSelect(const QModelIndex)));
	connect(btnClo, SIGNAL(clicked()), this, SLOT(btnCloClick()));
	connect(btnBid, SIGNAL(clicked()), this, SLOT(btnBidClick()));
	connect(btnSech, SIGNAL(clicked()), this, SLOT(updatePageSech()));
	connect(btnClea, SIGNAL(clicked()), this, SLOT(clearPageSech()));
	connect(btnBidClo, SIGNAL(clicked()), this, SLOT(btnBidCloClick()));
	connect(btnBidCha, SIGNAL(clicked()), this, SLOT(btnBidChaClick()));
	connect(btnBidCan, SIGNAL(clicked()), this, SLOT(btnBidCanClick()));
	connect(wTab, SIGNAL(currentChanged(int)), this, SLOT(tabChange(int)));
}

void TabBuyerWidget::IniPageComs()
{
	pageComs = new QWidget();
	//Model & View & Widget
	comsModel = new QStringListModel(pageComs);
	comsList = new QListView(pageComs);
	comsDetWidget = new QWidget(pageComs);
	lbComNam = new QLabel(QStringLiteral("名称"), comsDetWidget);
	lbComPri = new QLabel(QStringLiteral("单价"), comsDetWidget);
	lbComNum = new QLabel(QStringLiteral("数量"), comsDetWidget);
	lbComDes = new QLabel(QStringLiteral("描述"), comsDetWidget);
	leComNam = new QLineEdit(comsDetWidget);
	leComPri = new QLineEdit(comsDetWidget);
	leComNum = new QLineEdit(comsDetWidget);
	tbComDes = new QTextBrowser(comsDetWidget);
	btnBid = new QPushButton(QStringLiteral("出价"), comsDetWidget);
	btnClo = new QPushButton(QStringLiteral("关闭"), comsDetWidget);
	//Setting
	updatePageComs();
	comsList->setModel(comsModel);
	comsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	comsDetWidget->setFixedWidth(0);
	leComNam->setDisabled(true);
	leComPri->setDisabled(true);
	leComNum->setDisabled(true);
	//Layout
	QHBoxLayout* comsBtnLay = new QHBoxLayout();
	QVBoxLayout* comsDetLay = new QVBoxLayout(comsDetWidget);
	QHBoxLayout* comsLay = new QHBoxLayout(pageComs);

	comsBtnLay->setContentsMargins(0, 0, 0, 0);
	comsBtnLay->setSpacing(10);
	comsDetLay->setContentsMargins(20, 10, 0, 0);
	comsDetLay->setSpacing(10);
	comsLay->setContentsMargins(0, 0, 0, 20);
	comsLay->setSpacing(0);

	comsDetLay->addWidget(lbComNam);
	comsDetLay->addWidget(leComNam);
	comsDetLay->addWidget(lbComPri);
	comsDetLay->addWidget(leComPri);
	comsDetLay->addWidget(lbComNum);
	comsDetLay->addWidget(leComNum);
	comsDetLay->addWidget(lbComDes);
	comsDetLay->addWidget(tbComDes);
	comsBtnLay->addWidget(btnClo);
	comsBtnLay->addWidget(btnBid);
	comsDetLay->addLayout(comsBtnLay);
	comsLay->addWidget(comsList);
	comsLay->addWidget(comsDetWidget);
}
void TabBuyerWidget::IniPageSech()
{
	pageSech = new QWidget();
	//QLineEdit & QPushButton
	leSech = new QLineEdit(pageSech);
	btnSech = new QPushButton(QStringLiteral("搜索"), pageSech);
	btnClea = new QPushButton(QStringLiteral("清除"), pageSech);
	sechList = new QListWidget(pageSech);
	//Layout
	QHBoxLayout* sechLeLay = new QHBoxLayout();
	QVBoxLayout* sechLay = new QVBoxLayout(pageSech);

	sechLeLay->setMargin(0);
	sechLeLay->setSpacing(0);
	sechLay->setContentsMargins(0, 0, 0, 20);
	sechLay->setSpacing(0);

	//QSpacerItem* sechSpa = new QSpacerItem(400, 450, QSizePolicy::Expanding, QSizePolicy::Expanding);
	sechLeLay->addWidget(leSech);
	sechLeLay->addWidget(btnSech);
	sechLeLay->addWidget(btnClea);
	sechLay->addLayout(sechLeLay);
	sechLay->addWidget(sechList);
	//sechLay->addSpacerItem(sechSpa);
}
void TabBuyerWidget::IniPageBids()
{
	pageBids = new QWidget();
	//Model & View & Widget
	bidsModel = new QStringListModel(pageBids);
	bidsList = new QListView(pageBids);
	bidsDetWidget = new QWidget(pageBids);
	lbBidCid = new QLabel(QStringLiteral("商品ID"), bidsDetWidget);
	lbBidNam = new QLabel(QStringLiteral("商品名称"), bidsDetWidget);
	lbBidPri = new QLabel(QStringLiteral("竞拍单价"), bidsDetWidget);
	lbBidNum = new QLabel(QStringLiteral("竞拍数量"), bidsDetWidget);
	leBidCid = new QLineEdit(bidsDetWidget);
	leBidNam = new QLineEdit(bidsDetWidget);
	leBidPri = new QLineEdit(bidsDetWidget);
	leBidNum = new QLineEdit(bidsDetWidget);
	btnBidCha = new QPushButton(QStringLiteral("修改"), bidsDetWidget);
	btnBidClo = new QPushButton(QStringLiteral("关闭"), bidsDetWidget);
	btnBidCan = new QPushButton(QStringLiteral("取消报价"), bidsDetWidget);
	//Setting
	updatePageBids();
	leBidCid->setEnabled(false);
	leBidNam->setEnabled(false);
	bidsList->setModel(bidsModel);
	bidsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	bidsDetWidget->setFixedWidth(0);
	//Layout
	QHBoxLayout* bidsBtnLay = new QHBoxLayout();
	QVBoxLayout* bidsDetLay = new QVBoxLayout(bidsDetWidget);
	QHBoxLayout* bidsLay = new QHBoxLayout(pageBids);

	bidsBtnLay->setContentsMargins(0, 0, 0, 0);
	bidsBtnLay->setSpacing(10);
	bidsDetLay->setContentsMargins(20, 10, 0, 0);
	bidsDetLay->setSpacing(10);
	bidsLay->setContentsMargins(0, 0, 0, 20);
	bidsLay->setSpacing(0);

	bidsDetLay->addWidget(lbBidCid);
	bidsDetLay->addWidget(leBidCid);
	bidsDetLay->addWidget(lbBidNam);
	bidsDetLay->addWidget(leBidNam);
	bidsDetLay->addWidget(lbBidPri);
	bidsDetLay->addWidget(leBidPri);
	bidsDetLay->addWidget(lbBidNum);
	bidsDetLay->addWidget(leBidNum);
	bidsBtnLay->addWidget(btnBidClo);
	bidsBtnLay->addWidget(btnBidCha);
	bidsBtnLay->addWidget(btnBidCan);
	bidsDetLay->addLayout(bidsBtnLay);
	bidsLay->addWidget(bidsList);
	bidsLay->addWidget(bidsDetWidget);
}
void TabBuyerWidget::IniPageOrds()
{
	pageOrds = new QWidget();
	//Model & View & Widget
	ordsModel = new QStringListModel(pageOrds);
	ordsList = new QListView(pageOrds);
	ordsDetWidget = new QWidget(pageOrds);
	lbOrdOid = new QLabel(ordsDetWidget);
	lbOrdCid = new QLabel(ordsDetWidget);
	lbOrdPri = new QLabel(ordsDetWidget);
	lbOrdNum = new QLabel(ordsDetWidget);
	lbOrdDat = new QLabel(ordsDetWidget);
	lbOrdSid = new QLabel(ordsDetWidget);
	lbOrdBid = new QLabel(ordsDetWidget);
	lbOrdOidDes = new QLabel(QStringLiteral("订单号"), ordsDetWidget);
	lbOrdCidDes = new QLabel(QStringLiteral("商品号"), ordsDetWidget);
	lbOrdSidDes = new QLabel(QStringLiteral("卖家ID"), ordsDetWidget);
	lbOrdBidDes = new QLabel(QStringLiteral("买家ID"), ordsDetWidget);
	lbOrdPriDes = new QLabel(QStringLiteral("成交单价"), ordsDetWidget);
	lbOrdNumDes = new QLabel(QStringLiteral("成交数量"), ordsDetWidget);
	lbOrdDatDes = new QLabel(QStringLiteral("成交日期"), ordsDetWidget);
	//Setting
	updatePageOrds();
	ordsList->setModel(ordsModel);
	ordsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ordsDetWidget->setFixedWidth(0);
	//Layout
	QVBoxLayout* ordsDetLay = new QVBoxLayout(ordsDetWidget);
	QHBoxLayout* ordsLay = new QHBoxLayout(pageOrds);

	ordsDetLay->setSpacing(10);
	ordsLay->setContentsMargins(0, 0, 0, 20);
	ordsLay->setSpacing(0);

	ordsDetLay->addWidget(lbOrdOidDes);
	ordsDetLay->addWidget(lbOrdOid);
	ordsDetLay->addWidget(lbOrdCidDes);
	ordsDetLay->addWidget(lbOrdCid);
	ordsDetLay->addWidget(lbOrdPriDes);
	ordsDetLay->addWidget(lbOrdPri);
	ordsDetLay->addWidget(lbOrdNumDes);
	ordsDetLay->addWidget(lbOrdNum);
	ordsDetLay->addWidget(lbOrdDatDes);
	ordsDetLay->addWidget(lbOrdDat);
	ordsDetLay->addWidget(lbOrdSidDes);
	ordsDetLay->addWidget(lbOrdSid);
	ordsDetLay->addWidget(lbOrdBidDes);
	ordsDetLay->addWidget(lbOrdBid);
	ordsLay->addWidget(ordsList);
	ordsLay->addWidget(ordsDetWidget);
}

void TabBuyerWidget::listComsSelect(const QModelIndex& index)
{
	cid = comsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.BuyerGetCommodityDetail(cid, com);
	leComNam->setText(QString::fromStdString(com.commodityName));
	leComPri->setText(QString::number(com.price));
	leComNum->setText(QString::number(com.number));
	tbComDes->setText(QString::fromStdString(com.description));
	comsDetWidget->setFixedWidth(170);
}
void TabBuyerWidget::listOrdsSelect(const QModelIndex& index)
{
	oid = ordsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.BuyerGetOrder(oid, ord);
	lbOrdOid->setText(QString::fromStdString(ord.orderID));
	lbOrdCid->setText(QString::fromStdString(ord.commodityID));
	lbOrdPri->setText(QString::number(ord.unitPrice));
	lbOrdNum->setText(QString::number(ord.number));
	lbOrdDat->setText(QString::fromStdString(ord.date));
	lbOrdSid->setText(QString::fromStdString(ord.sellerID));
	lbOrdBid->setText(QString::fromStdString(ord.buyerID));
	ordsDetWidget->setFixedWidth(170);
}
void TabBuyerWidget::listBidsSelect(const QModelIndex& index)
{
	std::string bidCid = bidsModel->data(index).toString().toStdString().substr(0, 4);
	CommodityModel bidCom;
	pCon.BuyerGetCommodityDetail(bidCid, bidCom);
	leBidCid->setText(QString::fromStdString(bidCid));
	leBidNam->setText(QString::fromStdString(bidCom.commodityName));
	leBidPri->setText(QString::number(bids[bidCid][0].offer));
	leBidNum->setText(QString::number(bids[bidCid][0].number));
	bidsDetWidget->setFixedWidth(170);
}
void TabBuyerWidget::btnCloClick()
{
	comsDetWidget->setFixedWidth(0);
}
void TabBuyerWidget::btnBidClick()
{
	BuyerBidWidget wBid(cid);
	wBid.exec();
	updatePageComs();
}
void TabBuyerWidget::updatePageComs()
{
	QStringList list;
	map<std::string, CommodityModel> coms;
	pCon.BuyerGetCommodityList(coms);
	for (auto pair : coms)
	{
		QString cid = QString::fromStdString(pair.first);
		QString nam = QString::fromStdString(pair.second.commodityName);
		QString pri = QString::number(pair.second.price);
		QString num = QString::number(pair.second.number);
		QString dat = QString::fromStdString(pair.second.addedDate);
		list << cid + "\t" + nam + "\t" + pri + "\t" + num + "\t" + dat;
	}
	comsModel->setStringList(list);
}
void TabBuyerWidget::updatePageSech()
{
	sechList->clear();
	std::string name = leSech->text().toStdString();
	map<std::string, CommodityModel> sechComs;
	pCon.BuyerSearchCommodity(name, sechComs);
	if (sechComs.size() == 0)
	{
		sechList->addItem(QStringLiteral("未找到该商品"));
		return;
	}
	for (auto pair : sechComs)
	{
		QString cid = QString::fromStdString(pair.first);
		QString nam = QString::fromStdString(pair.second.commodityName);
		QString pri = QString::number(pair.second.price);
		QString num = QString::number(pair.second.number);
		QString dat = QString::fromStdString(pair.second.addedDate);
		QString des = QString::fromStdString(pair.second.description);
		sechList->addItem(cid + "\t" + nam + "\t" + pri + "\t" + num + "\t" + dat + "\t" + des);
	}
}
void TabBuyerWidget::updatePageBids()
{
	QStringList list;
	bids.clear();
	pCon.BuyerGetBidList(bids);
	for (auto pair : bids)
	{
		CommodityModel bidCom;
		pCon.BuyerGetCommodityDetail(pair.first, bidCom);
		QString cid = QString::fromStdString(pair.first);
		QString nam = QString::fromStdString(bidCom.commodityName);
		QString pri = QString::number(pair.second[0].offer);
		QString num = QString::number(pair.second[0].number);
		list << cid + "\t" + nam + "\t" + pri + "\t" + num + "\t";
	}
	bidsModel->setStringList(list);
}
void TabBuyerWidget::updatePageOrds()
{
	QStringList list;
	map<std::string, OrderModel> ords;
	pCon.BuyerGetHistoryOrderList(ords);
	for (auto pair : ords)
	{
		QString oid = QString::fromStdString(pair.first);
		QString cid = QString::fromStdString(pair.second.commodityID);
		QString pri = QString::number(pair.second.unitPrice);
		QString num = QString::number(pair.second.number);
		QString dat = QString::fromStdString(pair.second.date);
		QString sid = QString::fromStdString(pair.second.sellerID);
		QString bid = QString::fromStdString(pair.second.buyerID);
		list << oid + "\t" + cid + "\t" + pri + "\t" + num + "\t" + dat + "\t" + sid + "\t" + bid;
	}
	ordsModel->setStringList(list);
}
void TabBuyerWidget::clearPageSech()
{
	sechList->clear();
}
void TabBuyerWidget::btnBidCloClick()
{
	bidsDetWidget->setFixedWidth(0);
}
void TabBuyerWidget::btnBidChaClick()
{
	std::string bidCid = leBidCid->text().toStdString();
	double bidPir = leBidPri->text().toDouble();
	int bidNum = leBidNum->text().toInt();
	if (bidPir == bids[bidCid][0].offer && bidNum == bids[bidCid][0].number)
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("请作出修改"));
		return;
	}
	if (pCon.BuyerBidChangeOffer(bidPir, bidCid, bidNum))
	{
		updatePageBids();
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改成功"));
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改失败"));
	}
}
void TabBuyerWidget::btnBidCanClick()
{
	std::string bidCid = leBidCid->text().toStdString();
	if (pCon.BuyerBidCancel(bidCid))
	{
		btnBidCloClick();
		updatePageBids();
		QMessageBox::information(this, QStringLiteral("取消结果"), QStringLiteral("取消成功"));
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("取消结果"), QStringLiteral("取消失败"));
	}
}
void TabBuyerWidget::tabChange(int index)
{
	if (index == 0)
	{
		updatePageComs();
	}
	else if (index == 2)
	{
		updatePageBids();
	}
	else if (index == 3)
	{
		updatePageOrds();
	}
}