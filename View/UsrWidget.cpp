#include "UsrWidget.h"

UsrWidget::UsrWidget(QWidget *parent) : QWidget(parent)
{
	IniUI();
	IniStyleSheet();
	IniSignalSlots();
}
UsrWidget::~UsrWidget()
{}

void UsrWidget::IniUI()
{
	//UsrWidget
	QRect rect = QApplication::desktop()->screenGeometry();
	this->resize(700, 500);
	this->move((rect.width() - this->width()) / 2, (rect.height() - this->height()) / 2);
	//QRadioButton
	btnUsr = new QRadioButton(QStringLiteral("个人信息"));
	btnBuyer = new QRadioButton(QStringLiteral("我是买家"));
	btnSeller = new QRadioButton(QStringLiteral("我是卖家"));
	btnUsr->setObjectName("btnUsr");
	btnBuyer->setObjectName("btnBuyer");
	btnSeller->setObjectName("btnSeller");
	QWidget* wRadio = new QWidget();

	wRadio->setObjectName("wRadio");
	btnUsr->setProperty("MainRadio", true);
	btnBuyer->setProperty("MainRadio", true);
	btnSeller->setProperty("MainRadio", true);

	QVBoxLayout* radioLay = new QVBoxLayout(wRadio);
	QSpacerItem* radioSpacer = new QSpacerItem(80, 350, QSizePolicy::Fixed, QSizePolicy::Expanding);
	radioLay->setMargin(0);
	radioLay->setSpacing(0);
	radioLay->addWidget(btnUsr);
	radioLay->addWidget(btnBuyer);
	radioLay->addWidget(btnSeller);
	radioLay->addSpacerItem(radioSpacer);
	//Tab Widgets
	wUsr = new TabUsrWidget();
	wBuyer = new TabBuyerWidget();
	wSeller = new TabSellerWidget();
	QVBoxLayout* stackLay = new QVBoxLayout();
	stackLay->setContentsMargins(20, 10, 20, 0);
	contentLay = new QStackedLayout(stackLay);
	contentLay->addWidget(wUsr);
	contentLay->addWidget(wBuyer);
	contentLay->addWidget(wSeller);
	//QLayout
	QHBoxLayout* widgetLay = new QHBoxLayout(this);
	widgetLay->setMargin(0);
	widgetLay->setSpacing(0);
	widgetLay->addWidget(wRadio);
	widgetLay->addLayout(stackLay);
}
void UsrWidget::IniStyleSheet()
{
	QFile file(":/Qss/UsrStyle.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QString::fromLatin1(file.readAll());
	this->setStyleSheet(styleSheet);
}
void UsrWidget::IniSignalSlots()
{
	connect(btnUsr, SIGNAL(clicked(bool)), this, SLOT(btnRadioClick(bool)));
	connect(btnBuyer, SIGNAL(clicked(bool)), this, SLOT(btnRadioClick(bool)));
	connect(btnSeller, SIGNAL(clicked(bool)), this, SLOT(btnRadioClick(bool)));
	connect(wUsr->btnInfoLogout, SIGNAL(clicked()), this, SLOT(btnLogoutClick()));
}

void UsrWidget::btnRadioClick(bool checked)
{
	if (checked)
	{
		if ((QRadioButton*)sender() == btnUsr)
		{
			wUsr->updatePageInfo();
			wUsr->updatePageChar();
			contentLay->setCurrentWidget(wUsr);
		}
		else if ((QRadioButton*)sender() == btnBuyer)
		{
			wBuyer->updatePageComs();
			wBuyer->updatePageBids();
			wBuyer->updatePageOrds();
			contentLay->setCurrentWidget(wBuyer);
		}
		else if ((QRadioButton*)sender() == btnSeller)
		{
			wSeller->UpdatePageComs();
			wSeller->UpdatePageOrds();
			contentLay->setCurrentWidget(wSeller);
		}
	}
}
void UsrWidget::btnLogoutClick()
{
	pCon.Logout();
	emit UsrWidgetClosed();
	this->hide();
}