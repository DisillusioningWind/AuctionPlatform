# AuctionPlatform
CS高程课设 商品竞拍平台 MVC架构，Qt作为GUI库，使用qss使其具有更加现代的界面
## 架构
### Model
所有的模型，包括用户模型、商品模型、竞拍出价（简称竞单）模型及订单模型，模型中除初始化函数外无任何逻辑，所有的业务逻辑均集中在Controller中。  
Timer.h中使用多线程简易实现了计时器功能，在Controller的初始化函数中将创建新线程启动计时器，析构函数中会释放计时器线程资源。（老实说这个计时器实现的太屎了，
线程的创建应该放到计时器类内部才对，但是我懒得动了）
### Controller
整个项目唯一的控制器类，所有逻辑均集中实现在该类中，包括管理员用户名及密码设置，文件读写（可以设置用户、商品、竞单、订单文件相对路径，记录到唯一的map中），
用户、买家、卖家逻辑，以及获得控制器状态（存在用户登录、登出、管理员登陆三个状态，所有的API只有在对应的状态中才能执行，否则直接返回false）  
控制器类的实例化位于GlobalVariable.cpp中，在需要使用控制器逻辑的位置应包含GlobalVariable.h头文件。  
Global.h文件包含了除Qt外所有文件所需的头文件，所以Model & Controller部分可以脱离Qt使用其他GUI库。
### View
所有的QWidget，其中AdminWidget、LoginWidget、UsrWidget作为顶级窗口使用，其余widget作为内部Tab控件（BuyerBidWidget作为弹窗），为简化逻辑，在LoginWidget中会初始化另外两个窗口，但只有登录后会显示其他窗口。  
所有的Widget均不使用.ui文件，使用纯代码实现界面，初始化大致分为IniUI（创建控件并安排布局）、IniStyleSheet（设置样式表，说真的，虽然够用，但对比css有些弱）、IniSignalSlot（槽函数绑定）三个函数。
### Qss
LoginWidget和UsrWidget的美化qss（未完全完成，懒死），包含在Resource.qrc中，所以使用时按url引用即可。
### 其他
main.cpp 主函数，只包含LoginWidget.h头文件。
*.txt    用户、商品、竞单、订单文件
