#include "LoginWidget.h"

LoginWidget::LoginWidget(QWidget *parent) : QDialog(parent)
{
	IniUI();
	IniStyleSheet();
	IniSignalSlots();
}
LoginWidget::~LoginWidget()
{}

void LoginWidget::IniUI()
{
	//QWidget
	this->setFixedSize(500, 450);
	this->setWindowTitle("Platform Login");
	this->setAttribute(Qt::WA_DeleteOnClose);//release resources when closed
	this->setWindowFlags(Qt::SplashScreen | windowFlags());
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
	lePwd->setEchoMode(QLineEdit::Password);
	QVBoxLayout* comboLay = new QVBoxLayout();
	comboLay->setContentsMargins(40, 0, 40, 0);
	comboLay->setSpacing(0);
	comboLay->addWidget(lbName);
	comboLay->addWidget(leName);
	comboLay->addWidget(lbPwd);
	comboLay->addWidget(lePwd);
	//Test
	leName->setText("usr");
	lePwd->setText("pwd");
	//QPushButton
	btnUsrLogin = new QPushButton(QStringLiteral("用户登录"), this);
	btnUsrRegister = new QPushButton(QStringLiteral("用户注册"), this);
	btnAdminLogin = new QPushButton(QStringLiteral("管理员登录"), this);
	btnExit = new QPushButton(QStringLiteral("退出"), this);
	QHBoxLayout* btnLay = new QHBoxLayout();
	btnLay->setContentsMargins(40, 40, 40, 50);
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
void LoginWidget::IniStyleSheet()
{
	QFile file(":/Qss/LoginStyle.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QString::fromLatin1(file.readAll());
	this->setStyleSheet(styleSheet);
}
void LoginWidget::IniSignalSlots()
{
	connect(btnExit, SIGNAL(clicked()), this, SLOT(reject()));
	connect(btnUsrLogin, SIGNAL(clicked()), this, SLOT(btnUsrLoginClick()));
}

//slots
void LoginWidget::btnUsrLoginClick()
{
	string name = leName->text().toStdString();
	string pwd = lePwd->text().toStdString();
	if (pCon.UserLogin(name, pwd))
		accept();
	else
		qDebug() << "false";
}
//Event
void LoginWidget::mousePressEvent(QMouseEvent* e)
{
	if (e->button() == Qt::LeftButton)
	{
		mMoveState = true;
		mLastPos = e->pos();
	}
}
void LoginWidget::mouseMoveEvent(QMouseEvent* e)
{
	if (mMoveState)
	{
		move(e->pos() - mLastPos + pos());
	}
}
void LoginWidget::mouseReleaseEvent(QMouseEvent* e)
{
	Q_UNUSED(e);
	mMoveState = false;
}
void LoginWidget::keyPressEvent(QKeyEvent* e)
{
	if (e->key() == Qt::Key_Down && leName->hasFocus())
		lePwd->setFocus();
	else if (e->key() == Qt::Key_Up && lePwd->hasFocus())
		leName->setFocus();
	else if (e->key() == Qt::Key_Return)
		btnUsrLogin->clicked();
}