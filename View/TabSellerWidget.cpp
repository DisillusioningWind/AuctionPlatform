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
	IniPageComs();
	IniPageRele();
	IniPageOrds();
	//Add Tab
	wTab->addTab(pageComs, QStringLiteral("商品"));
	wTab->addTab(pageRele, QStringLiteral("发布"));
	wTab->addTab(pageOrds, QStringLiteral("订单"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setMargin(0);
	lay->setSpacing(0);
	lay->addWidget(lb);
	lay->addWidget(wTab);
}
void TabSellerWidget::IniSignalSlots()
{
	connect(comsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listComsSelect(const QModelIndex)));
	connect(ordsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listOrdsSelect(const QModelIndex)));
	connect(btnClo, SIGNAL(clicked()), this, SLOT(btnCloClick()));
	connect(btnReRe, SIGNAL(clicked()), this, SLOT(btnReReClick()));
	connect(btnBid, SIGNAL(clicked()), this, SLOT(btnBidClick()));
	connect(wTab, SIGNAL(currentChanged(int)), this, SLOT(tabChange(int)));
}

void TabSellerWidget::IniPageComs()
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
	tbComDes = new QTextEdit(comsDetWidget);
	btnComStUp = new QRadioButton(QStringLiteral("在售"), comsDetWidget);
	btnComStDo = new QRadioButton(QStringLiteral("下架"), comsDetWidget);
	btnBid = new QPushButton(QStringLiteral("修改"), comsDetWidget);
	btnClo = new QPushButton(QStringLiteral("关闭"), comsDetWidget);
	//Setting
	UpdatePageComs();
	comsList->setModel(comsModel);
	comsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	comsDetWidget->setFixedWidth(0);
	leComNam->setDisabled(false);
	leComPri->setDisabled(false);
	leComNum->setDisabled(false);
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

	comsDetLay->addWidget(btnComStUp);
	comsDetLay->addWidget(btnComStDo);
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
void TabSellerWidget::IniPageRele()
{
	pageRele = new QWidget();
	//QLabel & QLineEdit & QTextEdit & QPushButton
	lbReNam = new QLabel(QStringLiteral("商品名称"), pageRele);
	lbRePri = new QLabel(QStringLiteral("商品价格"), pageRele);
	lbReNum = new QLabel(QStringLiteral("商品数量"), pageRele);
	lbReDes = new QLabel(QStringLiteral("商品描述"), pageRele);
	leReNam = new QLineEdit(pageRele);
	leRePri = new QLineEdit(pageRele);
	leReNum = new QLineEdit(pageRele);
	teReDes = new QTextEdit(pageRele);
	btnReRe = new QPushButton(QStringLiteral("发布"), pageRele);

	//Layout
	QGridLayout* releDetLay = new QGridLayout();
	QVBoxLayout* releLay = new QVBoxLayout(pageRele);

	releDetLay->setMargin(0);
	releDetLay->setSpacing(10);
	releLay->setContentsMargins(0, 10, 0, 30);
	releLay->setSpacing(10);

	releDetLay->addWidget(lbReNam, 1, 1, 1, 2);
	releDetLay->addWidget(leReNam, 2, 1, 1, 2);
	releDetLay->addWidget(lbRePri, 3, 1);
	releDetLay->addWidget(lbReNum, 3, 2);
	releDetLay->addWidget(leRePri, 4, 1);
	releDetLay->addWidget(leReNum, 4, 2);
	releDetLay->addWidget(lbReDes, 5, 1, 1, 2);
	releLay->addLayout(releDetLay);
	releLay->addWidget(teReDes);
	releLay->addWidget(btnReRe);
}
void TabSellerWidget::IniPageOrds()
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
	UpdatePageOrds();
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
void TabSellerWidget::UpdatePageComs()
{
	QStringList list;
	map<std::string, CommodityModel> coms;
	pCon.SellerGetCommodityList(coms);
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
void TabSellerWidget::UpdatePageOrds()
{
	QStringList list;
	map<std::string, OrderModel> ords;
	pCon.SellerGetHistoryOrderList(ords);
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

void TabSellerWidget::btnReReClick()
{
	//valid check
	std::string name = leReNam->text().toStdString();
	double pri = leRePri->text().toDouble();
	int num = leReNum->text().toInt();
	std::string des = teReDes->toPlainText().toStdString();
	if (name.empty() || pri == 0 || num == 0)
	{
		QMessageBox::information(this, QStringLiteral("发布结果"), QStringLiteral("请补全信息"));
		return;
	}
	if (pCon.SellerReleaseCommodity(name, pri, num, des))
	{
		QMessageBox::information(this, QStringLiteral("发布结果"), QStringLiteral("发布成功"));
		leReNam->clear();
		leRePri->clear();
		leReNum->clear();
		teReDes->clear();
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("发布结果"), QStringLiteral("发布失败"));
	}
}
void TabSellerWidget::listComsSelect(const QModelIndex& index)
{
	cid = comsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.SellerGetCommodity(cid, com);
	leComNam->setText(QString::fromStdString(com.commodityName));
	leComPri->setText(QString::number(com.price));
	leComNum->setText(QString::number(com.number));
	tbComDes->setText(QString::fromStdString(com.description));
	btnComStUp->setChecked(com.state);
	btnComStDo->setChecked(!com.state);
	comsDetWidget->setFixedWidth(170);
}
void TabSellerWidget::listOrdsSelect(const QModelIndex& index)
{
	oid = ordsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.SellerGetOrder(oid, ord);
	lbOrdOid->setText(QString::fromStdString(ord.orderID));
	lbOrdCid->setText(QString::fromStdString(ord.commodityID));
	lbOrdPri->setText(QString::number(ord.unitPrice));
	lbOrdNum->setText(QString::number(ord.number));
	lbOrdDat->setText(QString::fromStdString(ord.date));
	lbOrdSid->setText(QString::fromStdString(ord.sellerID));
	lbOrdBid->setText(QString::fromStdString(ord.buyerID));
	ordsDetWidget->setFixedWidth(170);
}
void TabSellerWidget::btnCloClick()
{
	comsDetWidget->setFixedWidth(0);
}
void TabSellerWidget::btnBidClick()
{
	pCon.SellerGetCommodity(cid, com);
	std::string name = leComNam->text().toStdString();
	double pri = leComPri->text().toDouble();
	int num = leComNum->text().toInt();
	std::string des = tbComDes->toPlainText().toStdString();
	bool state = btnComStUp->isChecked();
	if (pCon.SellerModifyCommodityInfo(cid, pri, des, num, name))
	{
		QString Qcid = QString::fromStdString(cid);
		QString Qnam = QString::fromStdString(name);
		QString Qpri = QString::number(pri);
		QString Qnum = QString::number(num);
		QString Qdat = QString::fromStdString(com.addedDate);
		QString Qsum = Qcid + "\t" + Qnam + "\t" + Qpri + "\t" + Qnum + "\t" + Qdat;
		comsModel->setData(comsList->currentIndex(), Qsum);
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改成功"));
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改失败"));
	}
	if (com.state != state)
	{
		if (state)
			pCon.SellerUpshelfCommodity(cid);
		else
			pCon.SellerDownshelfCommodity(cid);
	}
}
void TabSellerWidget::tabChange(int index)
{
	if (index == 0)
	{
		UpdatePageComs();
	}
	else if (index == 2)
	{
		UpdatePageOrds();
	}
}