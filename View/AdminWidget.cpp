#include "AdminWidget.h"

AdminWidget::AdminWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniStyleSheet();
	IniSignalSlots();
}
AdminWidget::~AdminWidget()
{}

void AdminWidget::IniUI()
{
	//Window
	this->resize(700, 500);
	//Widget
	btnLogout = new QPushButton(QStringLiteral("退出登录"), this);
	wTab = new QTabWidget(this);
	//Page
	IniPageUsrs();
	IniPageComs();
	IniPageOrds();
	//Add Tab
	wTab->addTab(pageUsrs, QStringLiteral("用户"));
	wTab->addTab(pageComs, QStringLiteral("商品"));
	wTab->addTab(pageOrds, QStringLiteral("订单"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setContentsMargins(20, 0, 20, 20);
	lay->setSpacing(0);
	lay->addWidget(wTab);
	lay->addWidget(btnLogout);
}
void AdminWidget::IniStyleSheet()
{
	QFile file(":/Qss/UsrStyle.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QString::fromLatin1(file.readAll());
	this->setStyleSheet(styleSheet);
}
void AdminWidget::IniSignalSlots()
{
	connect(usrsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listUsrsSelect(const QModelIndex)));
	connect(comsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listComsSelect(const QModelIndex)));
	connect(ordsList, SIGNAL(clicked(const QModelIndex)), this, SLOT(listOrdsSelect(const QModelIndex)));
	connect(btnLogout, SIGNAL(clicked()), this, SLOT(btnLogoutClick()));
	connect(btnComClo, SIGNAL(clicked()), this, SLOT(btnComCloClick()));
	connect(btnComCha, SIGNAL(clicked()), this, SLOT(btnComChaClick()));
	connect(btnUsrClo, SIGNAL(clicked()), this, SLOT(btnUsrCloClick()));
	connect(btnUsrCha, SIGNAL(clicked()), this, SLOT(btnUsrChaClick()));
}

void AdminWidget::IniPageUsrs()
{
	pageUsrs = new QWidget();
	//Model & View & Widget
	usrsModel = new QStringListModel(pageUsrs);
	usrsList = new QListView(pageUsrs);
	usrsDetWidget = new QWidget(pageUsrs);
	lbDesUid = new QLabel(QStringLiteral("用户ID"), usrsDetWidget);
	lbDesNam = new QLabel(QStringLiteral("用户名"), usrsDetWidget);
	lbDesPwd = new QLabel(QStringLiteral("用户密码"), usrsDetWidget);
	lbDesPhn = new QLabel(QStringLiteral("联系方式"), usrsDetWidget);
	lbDesAdd = new QLabel(QStringLiteral("用户住址"), usrsDetWidget);
	lbDesBal = new QLabel(QStringLiteral("账户余额"), usrsDetWidget);
	lbUsrUid = new QLabel(usrsDetWidget);
	lbUsrNam = new QLabel(usrsDetWidget);
	lbUsrPwd = new QLabel(usrsDetWidget);
	lbUsrPhn = new QLabel(usrsDetWidget);
	lbUsrAdd = new QLabel(usrsDetWidget);
	lbUsrBal = new QLabel(usrsDetWidget);
	btnUsrStUp = new QRadioButton(QStringLiteral("激活"), usrsDetWidget);
	btnUsrStDo = new QRadioButton(QStringLiteral("禁止"), usrsDetWidget);
	btnUsrCha = new QPushButton(QStringLiteral("封禁"), usrsDetWidget);
	btnUsrClo = new QPushButton(QStringLiteral("关闭"), usrsDetWidget);
	//Setting
	updatePageUsrs();
	usrsList->setModel(usrsModel);
	usrsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	usrsDetWidget->setFixedWidth(0);
	//Layout
	QHBoxLayout* comsBtnLay = new QHBoxLayout();
	QVBoxLayout* comsDetLay = new QVBoxLayout(usrsDetWidget);
	QHBoxLayout* comsLay = new QHBoxLayout(pageUsrs);

	comsBtnLay->setContentsMargins(0, 0, 0, 0);
	comsBtnLay->setSpacing(10);
	comsDetLay->setContentsMargins(20, 10, 0, 0);
	comsDetLay->setSpacing(10);
	comsLay->setContentsMargins(0, 0, 0, 20);
	comsLay->setSpacing(0);

	comsDetLay->addWidget(btnUsrStUp);
	comsDetLay->addWidget(btnUsrStDo);
	comsDetLay->addWidget(lbDesUid);
	comsDetLay->addWidget(lbUsrUid);
	comsDetLay->addWidget(lbDesNam);
	comsDetLay->addWidget(lbUsrNam);
	comsDetLay->addWidget(lbDesPwd);
	comsDetLay->addWidget(lbUsrPwd);
	comsDetLay->addWidget(lbDesPhn);
	comsDetLay->addWidget(lbUsrPhn);
	comsDetLay->addWidget(lbDesAdd);
	comsDetLay->addWidget(lbUsrAdd);
	comsDetLay->addWidget(lbDesBal);
	comsDetLay->addWidget(lbUsrBal);
	comsBtnLay->addWidget(btnUsrClo);
	comsBtnLay->addWidget(btnUsrCha);
	comsDetLay->addLayout(comsBtnLay);
	comsLay->addWidget(usrsList);
	comsLay->addWidget(usrsDetWidget);
}
void AdminWidget::IniPageComs()
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
	btnComCha = new QPushButton(QStringLiteral("上下架"), comsDetWidget);
	btnComClo = new QPushButton(QStringLiteral("关闭"), comsDetWidget);
	//Setting
	updatePageComs();
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
	comsBtnLay->addWidget(btnComClo);
	comsBtnLay->addWidget(btnComCha);
	comsDetLay->addLayout(comsBtnLay);
	comsLay->addWidget(comsList);
	comsLay->addWidget(comsDetWidget);
}
void AdminWidget::IniPageOrds()
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

void AdminWidget::updatePageUsrs()
{
	QStringList list;
	map<std::string, UserModel> usrs;
	pCon.AdminGetUserList(usrs);
	for (auto pair : usrs)
	{
		QString uid = QString::fromStdString(pair.first);
		QString nam = QString::fromStdString(pair.second.userName);
		QString pwd = QString::fromStdString(pair.second.passWord);
		QString phn = QString::fromStdString(pair.second.phoneNumber);
		QString add = QString::fromStdString(pair.second.address);
		QString bal = QString::number(pair.second.balance);
		list << uid + "\t" + nam + "\t" + pwd + "\t" + phn + "\t" + add + "\t" + bal;
	}
	usrsModel->setStringList(list);
}
void AdminWidget::updatePageComs()
{
	QStringList list;
	map<std::string, CommodityModel> coms;
	pCon.AdminGetCommodityList(coms);
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
void AdminWidget::updatePageOrds()
{
	QStringList list;
	map<std::string, OrderModel> ords;
	pCon.AdminGetOrderList(ords);
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

void AdminWidget::listUsrsSelect(const QModelIndex& index)
{
	uid = usrsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.AdminGetUser(uid, usr);
	lbUsrUid->setText(QString::fromStdString(usr.userID));
	lbUsrNam->setText(QString::fromStdString(usr.userName));
	lbUsrPwd->setText(QString::fromStdString(usr.passWord));
	lbUsrPhn->setText(QString::fromStdString(usr.phoneNumber));
	lbUsrAdd->setText(QString::fromStdString(usr.address));
	lbUsrBal->setText(QString::number(usr.balance));
	btnUsrStUp->setChecked(usr.userState);
	btnUsrStDo->setChecked(!usr.userState);
	usrsDetWidget->setFixedWidth(170);
}
void AdminWidget::listComsSelect(const QModelIndex& index)
{
	cid = comsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.AdminGetCommodity(cid, com);
	leComNam->setText(QString::fromStdString(com.commodityName));
	leComPri->setText(QString::number(com.price));
	leComNum->setText(QString::number(com.number));
	tbComDes->setText(QString::fromStdString(com.description));
	btnComStUp->setChecked(com.state);
	btnComStDo->setChecked(!com.state);
	comsDetWidget->setFixedWidth(170);
}
void AdminWidget::listOrdsSelect(const QModelIndex& index)
{
	oid = ordsModel->data(index).toString().toStdString().substr(0, 4);
	pCon.AdminGetOrder(oid, ord);
	lbOrdOid->setText(QString::fromStdString(ord.orderID));
	lbOrdCid->setText(QString::fromStdString(ord.commodityID));
	lbOrdPri->setText(QString::number(ord.unitPrice));
	lbOrdNum->setText(QString::number(ord.number));
	lbOrdDat->setText(QString::fromStdString(ord.date));
	lbOrdSid->setText(QString::fromStdString(ord.sellerID));
	lbOrdBid->setText(QString::fromStdString(ord.buyerID));
	ordsDetWidget->setFixedWidth(170);
}

void AdminWidget::btnLogoutClick()
{
	pCon.Logout();
	emit AdminWidgetClosed();
	this->hide();
}
void AdminWidget::btnComCloClick()
{
	comsDetWidget->setFixedWidth(0);
}
void AdminWidget::btnComChaClick()
{
	pCon.AdminGetCommodity(cid, com);
	bool state = btnComStUp->isChecked();
	if (com.state != state)
	{
		if (state)
		{
			pCon.AdminUpshelfCommodity(cid);
			QMessageBox::information(this, QStringLiteral("上架结果"), QStringLiteral("上架成功"));
		}
		else
		{
			pCon.AdminDownshelfCommodity(cid);
			QMessageBox::information(this, QStringLiteral("下架结果"), QStringLiteral("下架成功"));
		}
	}
}
void AdminWidget::btnUsrCloClick()
{
	usrsDetWidget->setFixedWidth(0);
}
void AdminWidget::btnUsrChaClick()
{
	pCon.AdminGetUser(uid, usr);
	bool state = btnUsrStUp->isChecked();
	if (usr.userState != state)
	{
		if (state)
		{
			pCon.AdminActiveUser(uid);
			QMessageBox::information(this, QStringLiteral("操作结果"), QStringLiteral("解封成功"));
		}
		else
		{
			pCon.AdminDeactiveUser(uid);
			QMessageBox::information(this, QStringLiteral("操作结果"), QStringLiteral("封禁成功"));
		}
	}
}