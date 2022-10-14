#include "TabUsrWidget.h"

TabUsrWidget::TabUsrWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniSignalSlots();
}
TabUsrWidget::~TabUsrWidget()
{}

void TabUsrWidget::IniUI()
{
	lb = new QLabel(QStringLiteral("������Ϣ"), this);
	lb->setProperty("UperLb","true");
	wTab = new QTabWidget(this);
	//Page
	IniPageInfo();
	IniPageCharge();
	//Add Tab
	wTab->addTab(pageInfo, QStringLiteral("�˻�"));
	wTab->addTab(pageChar, QStringLiteral("��ֵ"));
	//Layout
	QVBoxLayout* lay = new QVBoxLayout(this);
	lay->setMargin(0);
	lay->setSpacing(0);
	lay->addWidget(lb);
	lay->addWidget(wTab);
}
void TabUsrWidget::IniSignalSlots()
{
	connect(btnTen, SIGNAL(clicked()), this, SLOT(btnBalClick()));
	connect(btnTew, SIGNAL(clicked()), this, SLOT(btnBalClick()));
	connect(btnFif, SIGNAL(clicked()), this, SLOT(btnBalClick()));
	connect(btnHun, SIGNAL(clicked()), this, SLOT(btnBalClick()));
	connect(btnTHu, SIGNAL(clicked()), this, SLOT(btnBalClick()));
	connect(btnCus, SIGNAL(clicked()), this, SLOT(btnBalClick()));
}

void TabUsrWidget::IniPageInfo()
{
	pageInfo = new QWidget();
	//QLabel
	lbName = new QLabel(QStringLiteral("�û���"), pageInfo);
	lbPwd = new QLabel(QStringLiteral("����"), pageInfo);
	lbPh = new QLabel(QStringLiteral("��ϵ��ʽ"), pageInfo);
	lbAdd = new QLabel(QStringLiteral("��ַ"), pageInfo);
	lbBal = new QLabel(QStringLiteral("���"), pageInfo);
	//QLineEdit
	UserModel usr;
	pCon.UserGetCurInfo(usr);
	leName = new QLineEdit(QString::fromStdString(usr.userName), pageInfo);
	lePwd = new QLineEdit(QString::fromStdString(usr.passWord), pageInfo);
	lePh = new QLineEdit(QString::fromStdString(usr.phoneNumber), pageInfo);
	leAdd = new QLineEdit(QString::fromStdString(usr.address), pageInfo);
	leBal = new QLineEdit(QString::number(usr.balance, 'f', 1), pageInfo);
	//QPushButton
	btnInfoChange = new QPushButton(QStringLiteral("�޸�"), pageInfo);
	btnInfoLogout = new QPushButton(QStringLiteral("ע��"), pageInfo);
	//Setting
	lbName->setProperty("UsrInfo", "true");
	lbPwd->setProperty("UsrInfo", "true");
	lbPh->setProperty("UsrInfo", "true");
	lbAdd->setProperty("UsrInfo", "true");
	lbBal->setProperty("UsrInfo", "true");
	leName->setProperty("UsrInfo", "true");
	lePwd->setProperty("UsrInfo", "true");
	lePh->setProperty("UsrInfo", "true");
	leAdd->setProperty("UsrInfo", "true");
	leBal->setProperty("UsrInfo", "true");
	btnInfoChange->setProperty("UsrInfo", "true");
	btnInfoLogout->setProperty("UsrInfo", "true");
	leBal->setEnabled(false);
	//btnInfoChange->setDisabled(true);
	//QLayout
	QVBoxLayout* infoLbLay = new QVBoxLayout();
	QVBoxLayout* infoLeLay = new QVBoxLayout();
	QHBoxLayout* infoComLay = new QHBoxLayout();
	QHBoxLayout* infoBtnLay = new QHBoxLayout();
	QVBoxLayout* infoLay = new QVBoxLayout(pageInfo);

	infoLbLay->setMargin(0);
	infoLbLay->setSpacing(5);
	infoLeLay->setMargin(0);
	infoLeLay->setSpacing(5);
	infoComLay->setMargin(0);
	infoComLay->setSpacing(0);
	infoBtnLay->setContentsMargins(0, 15, 0, 0);
	infoBtnLay->setSpacing(42);
	infoLay->setContentsMargins(0, 10, 0, 0);
	infoLay->setSpacing(0);

	QSpacerItem* infoSpa = new QSpacerItem(600, 450, QSizePolicy::Expanding, QSizePolicy::Expanding);
	QSpacerItem* infoLbSpa = new QSpacerItem(300, 100, QSizePolicy::Expanding, QSizePolicy::Expanding);
	QSpacerItem* infoBtnSpaLeft = new QSpacerItem(140, 30, QSizePolicy::Fixed, QSizePolicy::Expanding);
	QSpacerItem* infoBtnSpaRight = new QSpacerItem(255, 30, QSizePolicy::Expanding, QSizePolicy::Expanding);
	infoLbLay->addWidget(lbName);
	infoLbLay->addWidget(lbPwd);
	infoLbLay->addWidget(lbPh);
	infoLbLay->addWidget(lbAdd);
	infoLbLay->addWidget(lbBal);
	infoLeLay->addWidget(leName);
	infoLeLay->addWidget(lePwd);
	infoLeLay->addWidget(lePh);
	infoLeLay->addWidget(leAdd);
	infoLeLay->addWidget(leBal);
	infoComLay->addLayout(infoLbLay);
	infoComLay->addLayout(infoLeLay);
	infoComLay->addSpacerItem(infoLbSpa);
	infoBtnLay->addSpacerItem(infoBtnSpaLeft);
	infoBtnLay->addWidget(btnInfoChange);
	infoBtnLay->addWidget(btnInfoLogout);
	infoBtnLay->addSpacerItem(infoBtnSpaRight);
	infoLay->addLayout(infoComLay);
	infoLay->addLayout(infoBtnLay);
	infoLay->addSpacerItem(infoSpa);
}
void TabUsrWidget::IniPageCharge()
{
	pageChar = new QWidget();
	//QLabel
	UserModel usr;
	pCon.UserGetCurInfo(usr);
	lbBalDes = new QLabel(QStringLiteral("��ǰ�˻���"), pageChar);
	lbBalChar = new QLabel(QString::number(usr.balance, 'f', 1) + QStringLiteral("Ԫ"), pageChar);
	//QPushButton
	btnTen = new QRadioButton(QStringLiteral("10Ԫ"), pageChar);
	btnTew = new QRadioButton(QStringLiteral("20Ԫ"), pageChar);
	btnFif = new QRadioButton(QStringLiteral("50Ԫ"), pageChar);
	btnHun = new QRadioButton(QStringLiteral("100Ԫ"), pageChar);
	btnTHu = new QRadioButton(QStringLiteral("200Ԫ"), pageChar);
	btnCus = new QRadioButton(QStringLiteral("�Զ���"), pageChar);
	btnChar = new QPushButton(QStringLiteral("��ֵ"), pageChar);
	//QLineEdit
	leChar = new QLineEdit(pageChar);
	//Widget Setting
	btnChar->setProperty("UsrChar", "true");
	lbBalDes->setProperty("UsrChar", "true");
	lbBalChar->setProperty("UsrChar", "true");
	leChar->setProperty("UsrChar", "true");
	btnTen->setProperty("UsrChar", "true");
	btnTew->setProperty("UsrChar", "true");
	btnFif->setProperty("UsrChar", "true");
	btnHun->setProperty("UsrChar", "true");
	btnTHu->setProperty("UsrChar", "true");
	btnCus->setProperty("UsrChar", "true");
	lbBalChar->setObjectName("lbBalChar");
	leChar->hide();
	//QLayout
	QVBoxLayout* charBalLay = new QVBoxLayout();
	QVBoxLayout* charChaLay = new QVBoxLayout();
	QGridLayout* charBtnLay = new QGridLayout();
	QHBoxLayout* charLay = new QHBoxLayout(pageChar);

	charBalLay->setMargin(0);
	charBalLay->setSpacing(0);
	charChaLay->setMargin(0);
	charChaLay->setSpacing(15);
	charBtnLay->setContentsMargins(0, 0, 0, 0);
	charBtnLay->setHorizontalSpacing(15);
	charBtnLay->setVerticalSpacing(13);
	charLay->setContentsMargins(0, 10, 0, 0);
	charLay->setSpacing(0);

	QSpacerItem* charBalSpa = new QSpacerItem(400, 450, QSizePolicy::Expanding, QSizePolicy::Expanding);
	QSpacerItem* charChaSpa = new QSpacerItem(600, 450, QSizePolicy::Expanding, QSizePolicy::Expanding);
	charBalLay->addWidget(lbBalDes);
	charBalLay->addWidget(lbBalChar);
	charBalLay->addSpacerItem(charBalSpa);
	charBtnLay->addWidget(btnTen, 1, 1);
	charBtnLay->addWidget(btnTew, 1, 2);
	charBtnLay->addWidget(btnFif, 1, 3);
	charBtnLay->addWidget(btnHun, 2, 1);
	charBtnLay->addWidget(btnTHu, 2, 2);
	charBtnLay->addWidget(btnCus, 2, 3);
	charChaLay->addLayout(charBtnLay);
	charChaLay->addWidget(leChar);
	charChaLay->addWidget(btnChar);
	charChaLay->addSpacerItem(charChaSpa);
	charLay->addLayout(charBalLay);
	charLay->addLayout(charChaLay);
}

void TabUsrWidget::btnBalClick()
{
	QRadioButton* btn = (QRadioButton*)sender();	
	if (btn == btnCus)
		leChar->show();
	else
		leChar->hide();
}
void TabUsrWidget::btnCharClick()
{

}