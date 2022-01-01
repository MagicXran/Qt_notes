#include "MainWindows.h"
#include <QMenuBar>
#include <QToolBar>
#include "QStatusBar"
#include "QLabel"
#include "QDockWidget"
#include "QTextEdit"
#include "QIcon"
#include <QPixmap>
#include "QDialog"
#include "QBoxLayout"
#include "QMessageBox"

MainWindows::MainWindows(QWidget* parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);


	this->setWindowIcon(QIcon(QPixmap(":/resources/images/a3cne-hdzdt-001.ico")));
	this->resize(800, 600);
	this->setWindowTitle("MainWindow");

	// 创建一个菜单栏
	auto menuBar = new QMenuBar(this);

	//将菜单栏添加至主窗口
	this->setMenuBar(menuBar);

	//在菜单栏中添加菜单
	QMenu* file = new QMenu(tr("文件"), this);
	menuBar->addMenu(file);
	menuBar->addMenu(tr("编辑"));

	//菜单中添加菜单项
	//定义菜单项
	QAction* New = new QAction(tr("新建"));
	QAction* Save = new QAction(tr("保存"));
	QList<QAction*> action_list{ New, Save };
	//file->addActions(action_list);
	file->addAction(New);
	//添加分割线
	file->addSeparator();
	file->addAction(Save);

	//给菜单项,设置快捷键
	New->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));

	//让菜单项有对应动作! 查QAction 中的signals
	connect(New, &QAction::triggered, [&]()
		{
			qDebug() << "新建文件!\n";
		}
	);


	//创建一个工具栏
	QToolBar* tool_bar = new QToolBar(this);
	//添加至主窗口
	this->addToolBar(tool_bar);

	//将菜单项放入工具栏
	//tool_bar->addActions(action_list);
	tool_bar->addAction(New);
	//添加分割线
	tool_bar->addSeparator();
	tool_bar->addAction(Save);

	//默认允许浮动, 也可关闭浮动
	//所谓浮动,是单独存在无根之萍, 但仍可以拖动倚靠在四侧!
	tool_bar->setFloatable(true);

	//设置菜单栏允许停靠位置区域
	//只允许左右停靠
	tool_bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);


	//添加状态栏
	QStatusBar* stat_bar = new QStatusBar(this);
	// 一般添加控件,不是addXXX 就是 setXXX
	this->setStatusBar(stat_bar);

	//添加右侧部件
	QLabel* right = new QLabel(tr("右侧信息部件"), this);
	QLabel* left = new QLabel(tr("左侧信息部件"), this);
	stat_bar->addPermanentWidget(right);
	//添加左侧部件
	stat_bar->addWidget(left);


	//create dock widget
	QDockWidget* dock = new QDockWidget("铆接: 对话框", this);
	//add dock to main windows 
	this->addDockWidget(Qt::RightDockWidgetArea, dock);

	//向 dock 中添加部件
	// 多个小部件加入一个带 layout 的 widget, 再将widget加入dock, 才能正常显示.
	QWidget* btn_group = new QWidget(dock);
	QVBoxLayout* vBoxLayout_1 = new QVBoxLayout(btn_group);
	auto modal_btn = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "模态对话框", this);
	auto Nonmodal_btn = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "非模态对话框", this);

	auto box1 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "错误提示框", this);
	auto box2 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "警告提示框", this);
	auto box3 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "信息提示框", this);
	auto box4 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "询问提示框", this);

	vBoxLayout_1->addWidget(modal_btn);
	vBoxLayout_1->addWidget(Nonmodal_btn);
	vBoxLayout_1->addWidget(box1);
	vBoxLayout_1->addWidget(box2);
	vBoxLayout_1->addWidget(box3);
	vBoxLayout_1->addWidget(box4);

	dock->setWidget(btn_group);


	//设置铆接部件停靠位置
	dock->setAllowedAreas(Qt::DockWidgetArea_Mask);

	//设置一个中心部件
	QTextEdit* text = new QTextEdit("一船清梦压星河", this);
	this->setCentralWidget(text);

	//给菜单项添加图标
	//图片控件,在原图片
	QPixmap pix(":/resources/images/manufacturing_01.ico");
	//pix.load(":/resources/images/manufacturing_01.png");
	New->setIcon(QIcon(pix));


	//对话框
	//创建模态对话框
	QDialog* modal_dlg = new QDialog(this);
	modal_dlg->resize(200, 200);
	//作为模态显示对话框, 建议使用open()打开模态对话框, exec()可能出现bug,性能亦不高.
	//modal_dlg->open();
	connect(modal_btn, &QPushButton::clicked, modal_dlg, &QDialog::open);

	//非模态对话框
	QDialog* Nonmodal_dlg = new QDialog(this);
	Nonmodal_dlg->resize(200, 200);
	//Nonmodal_dlg->show();
	connect(Nonmodal_btn, &QPushButton::clicked, Nonmodal_dlg, &QDialog::show);


	//内置对话框
	connect(box1, &QPushButton::clicked, [&]()
		{
			QMessageBox::critical(this, "错误提示框", "严重错误哦! ");
		}
	);
	connect(box2, &QPushButton::clicked, [&]()
		{
			QMessageBox::warning(this, "警告提示框", "警告哦! ");
		}
	);
	connect(box3, &QPushButton::clicked, [&]()
		{
			QMessageBox::information(this, "信息提示框", "信息哦! ");
		}
	);
	connect(box4, &QPushButton::clicked, [&]()
		{
			qDebug() << QMessageBox::question(this, "询问提示框", "询问哦! ");
		}
	);

}

MainWindows::~MainWindows()
{
}
