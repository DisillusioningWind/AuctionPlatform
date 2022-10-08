#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) : QWidget(parent)
{
	iniUI();
	iniStyleSheet();
	iniSignalSlots();
}

LoginWidget::~LoginWidget()
{}

void LoginWidget::iniUI()
{
	//QWidget
	this->setFixedSize(500, 450);
	this->setWindowTitle("Platform Login");
	//QLabel Title
	lbTitle = new QLabel("AUCTION PLATFORM\nACCOUNT.", this);
	lbTitle->setObjectName("lbTitle");
	QHBoxLayout* titleLay = new QHBoxLayout();
	titleLay->setMargin(0);
	titleLay->addWidget(lbTitle);
	//QLabel Name,Pwd & QLineEdit Name,Pwd 
	lbName = new QLabel(QStringLiteral("用户名："), this);
	lbPwd = new QLabel(QStringLiteral("密码："), this);
	leName = new QLineEdit(this);
	lePwd = new QLineEdit(this);
	lePwd->setEchoMode(QLineEdit::EchoMode(2));
	QVBoxLayout* comboLay = new QVBoxLayout();
	comboLay->setContentsMargins(40, 0, 40, 0);
	comboLay->setSpacing(0);
	comboLay->addWidget(lbName);
	comboLay->addWidget(leName);
	comboLay->addWidget(lbPwd);
	comboLay->addWidget(lePwd);
	//QPushButton
	btnUsrLogin = new QPushButton(QStringLiteral("用户登录"), this);
	btnUsrRegister = new QPushButton(QStringLiteral("用户注册"), this);
	btnAdminLogin = new QPushButton(QStringLiteral("管理员登录"), this);
	btnExit = new QPushButton(QStringLiteral("退出"), this);
	QHBoxLayout* btnLay = new QHBoxLayout();
	btnLay->setContentsMargins(40, 30, 40, 60);
	btnLay->setSpacing(25);
	btnLay->addWidget(btnUsrLogin);
	btnLay->addWidget(btnUsrRegister);
	btnLay->addWidget(btnAdminLogin);
	btnLay->addWidget(btnExit);
	//QLayout
	QVBoxLayout* widgetLay = new QVBoxLayout(this);
	widgetLay->setMargin(0);
	widgetLay->addLayout(titleLay);
	widgetLay->addLayout(comboLay);
	widgetLay->addLayout(btnLay);
}

void LoginWidget::iniStyleSheet()
{
	QFile file("LoginStyle.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QString::fromLatin1(file.readAll());
	this->setStyleSheet(styleSheet);
}
void LoginWidget::iniSignalSlots()
{

}
