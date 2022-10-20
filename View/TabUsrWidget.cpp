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
	lb = new QLabel(QStringLiteral("个人信息"), this);
	lb->setProperty("UperLb","true");
	wTab = new QTabWidget(this);
	//Page
	IniPageInfo();
	IniPageCharge();
	//Add Tab
	wTab->addTab(pageInfo, QStringLiteral("账户"));
	wTab->addTab(pageChar, QStringLiteral("充值"));
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
	connect(btnChar, SIGNAL(clicked()), this, SLOT(btnCharClick()));
	connect(btnInfoChange, SIGNAL(clicked()), this, SLOT(btnInfoChangeClick()));
	//connect(btnInfoLogout, SIGNAL(clicked()), this, SLOT(btnInfoLogoutClick()));
	connect(wTab, SIGNAL(currentChanged(int)), this, SLOT(tabChange(int)));
}

void TabUsrWidget::IniPageInfo()
{
	pageInfo = new QWidget();
	//QLabel
	lbName = new QLabel(QStringLiteral("用户名"), pageInfo);
	lbPwd = new QLabel(QStringLiteral("密码"), pageInfo);
	lbPh = new QLabel(QStringLiteral("联系方式"), pageInfo);
	lbAdd = new QLabel(QStringLiteral("地址"), pageInfo);
	lbBal = new QLabel(QStringLiteral("余额"), pageInfo);
	//QLineEdit
	leName = new QLineEdit(pageInfo);
	lePwd = new QLineEdit(pageInfo);
	lePh = new QLineEdit(pageInfo);
	leAdd = new QLineEdit(pageInfo);
	leBal = new QLineEdit(pageInfo);
	//QPushButton
	btnInfoChange = new QPushButton(QStringLiteral("修改"), pageInfo);
	btnInfoLogout = new QPushButton(QStringLiteral("注销"), pageInfo);
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
	updatePageInfo();
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
	lbBalDes = new QLabel(QStringLiteral("当前账户余额："), pageChar);
	lbBalChar = new QLabel(pageChar);
	//QPushButton
	btnTen = new QRadioButton(QStringLiteral("10元"), pageChar);
	btnTew = new QRadioButton(QStringLiteral("20元"), pageChar);
	btnFif = new QRadioButton(QStringLiteral("50元"), pageChar);
	btnHun = new QRadioButton(QStringLiteral("100元"), pageChar);
	btnTHu = new QRadioButton(QStringLiteral("200元"), pageChar);
	btnCus = new QRadioButton(QStringLiteral("自定义"), pageChar);
	btnChar = new QPushButton(QStringLiteral("充值"), pageChar);
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
	updatePageChar();
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
	if (btnTen->isChecked())
	{
		pCon.UserModifyCurInfo("", "", "", "", 10);
		btnTen->setChecked(false);
	}
	else if (btnTew->isChecked())
	{
		pCon.UserModifyCurInfo("", "", "", "", 20);
		btnTew->setChecked(false);
	}
	else if (btnFif->isChecked())
	{
		pCon.UserModifyCurInfo("", "", "", "", 50);
		btnFif->setChecked(false);
	}
	else if (btnHun->isChecked())
	{
		pCon.UserModifyCurInfo("", "", "", "", 100);
		btnHun->setChecked(false);
	}
	else if (btnTHu->isChecked())
	{
		pCon.UserModifyCurInfo("", "", "", "", 200);
		btnTHu->setChecked(false);
	}
	else if (btnCus->isChecked())
	{
		double newBal = leChar->text().toDouble();
		pCon.UserModifyCurInfo("", "", "", "", newBal);
		leChar->clear();
		leChar->hide();
		btnCus->setChecked(false);
	}
	QMessageBox::information(this, QStringLiteral("充值结果"), QStringLiteral("充值成功"));
	updatePageChar();
}
void TabUsrWidget::btnInfoChangeClick()
{
	UserModel usr;
	pCon.UserGetCurInfo(usr);
	std::string nam = leName->text().toStdString();
	std::string pwd = lePwd->text().toStdString();
	std::string phn = lePh->text().toStdString();
	std::string add = leAdd->text().toStdString();
	if (nam == usr.userName && pwd == usr.passWord &&
		phn == usr.phoneNumber && add == usr.address)
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("请至少作出一项改动"));
		return;
	}
	if (pCon.UserModifyCurInfo(nam, pwd, phn, add))
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改成功"));
	}
	else
	{
		QMessageBox::information(this, QStringLiteral("修改结果"), QStringLiteral("修改失败"));
	}
}
void TabUsrWidget::btnInfoChangeState()
{

}
//void TabUsrWidget::btnInfoLogoutClick()
//{
//	pCon.Logout();
//	emit UsrWidgetClosed();
//	this->parentWidget()->close();
//	this->parentWidget()->hide();
//	if (login->exec() == QDialog::Accepted)
//	{
//		if (pCon.GetConState() == ConState::stUserLogin)
//		{
//			updatePageInfo();
//			this->parentWidget()->show();
//		}
//	}
//	else
//	{
//		this->parentWidget()->close();
//	}
//}
void TabUsrWidget::updatePageInfo()
{
	UserModel usr;
	pCon.UserGetCurInfo(usr);
	leName->setText(QString::fromStdString(usr.userName));
	lePwd->setText(QString::fromStdString(usr.passWord));
	lePh->setText(QString::fromStdString(usr.phoneNumber));
	leAdd->setText(QString::fromStdString(usr.address));
	leBal->setText(QString::number(usr.balance, 'f', 1));
}
void TabUsrWidget::updatePageChar()
{
	UserModel usr;
	pCon.UserGetCurInfo(usr);
	lbBalChar->setText(QString::number(usr.balance, 'f', 1) + QStringLiteral("元"));
}
void TabUsrWidget::tabChange(int index)
{
	if (index == 0)
	{
		updatePageInfo();
	}
	else if (index == 1)
	{
		updatePageChar();
	}
}