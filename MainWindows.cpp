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
#include "QFontDialog"
#include "QFileDialog"
#include <QPushButton>

MainWindows::MainWindows(QWidget* parent)
	: QMainWindow(parent)
{
	//ui.setupUi(this);


	this->setWindowIcon(QIcon(QPixmap(":/resources/images/a3cne-hdzdt-001.ico")));
	this->resize(800, 600);
	this->setWindowTitle("MainWindow");

	// ����һ���˵���
	auto menuBar = new QMenuBar(this);

	//���˵��������������
	this->setMenuBar(menuBar);

	//�ڲ˵�������Ӳ˵�
	QMenu* file = new QMenu(tr("�ļ�"), this);
	menuBar->addMenu(file);
	menuBar->addMenu(tr("�༭"));

	//�˵�����Ӳ˵���
	//����˵���
	QAction* New = new QAction(tr("�½�"));
	QAction* Save = new QAction(tr("����"));
	QList<QAction*> action_list{ New, Save };
	//file->addActions(action_list);
	file->addAction(New);
	//��ӷָ���
	file->addSeparator();
	file->addAction(Save);

	//���˵���,���ÿ�ݼ�
	New->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));

	//�ò˵����ж�Ӧ����! ��QAction �е�signals
	connect(New, &QAction::triggered, [&]()
		{
			qDebug() << "�½��ļ�!\n";
		}
	);


	//����һ��������
	QToolBar* tool_bar = new QToolBar(this);
	//�����������
	this->addToolBar(tool_bar);

	//���˵�����빤����
	//tool_bar->addActions(action_list);
	tool_bar->addAction(New);
	//��ӷָ���
	tool_bar->addSeparator();
	tool_bar->addAction(Save);

	//Ĭ��������, Ҳ�ɹرո���
	//��ν����,�ǵ��������޸�֮Ƽ, ���Կ����϶��п����Ĳ�!
	tool_bar->setFloatable(true);

	//���ò˵�������ͣ��λ������
	//ֻ��������ͣ��
	tool_bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);


	//���״̬��
	QStatusBar* stat_bar = new QStatusBar(this);
	// һ����ӿؼ�,����addXXX ���� setXXX
	this->setStatusBar(stat_bar);

	//����Ҳಿ��
	QLabel* right = new QLabel(tr("�Ҳ���Ϣ����"), this);
	QLabel* left = new QLabel(tr("�����Ϣ����"), this);
	stat_bar->addPermanentWidget(right);
	//�����ಿ��
	stat_bar->addWidget(left);


	//create dock widget
	QDockWidget* dock = new QDockWidget("í��: �Ի���", this);
	//add dock to main windows 
	this->addDockWidget(Qt::RightDockWidgetArea, dock);

	//�� dock ����Ӳ���
	// ���С��������һ���� layout �� widget, �ٽ�widget����dock, ����������ʾ.
	QWidget* btn_group = new QWidget(dock);
	QVBoxLayout* vBoxLayout_1 = new QVBoxLayout(btn_group);
	auto modal_btn = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "ģ̬�Ի���", this);
	auto Nonmodal_btn = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "��ģ̬�Ի���", this);

	auto box1 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "������ʾ��", this);
	auto box2 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "������ʾ��", this);
	auto box3 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "��Ϣ��ʾ��", this);
	auto box4 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "ѯ����ʾ��", this);
	auto box5 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "�ļ��Ի���", this);
	auto box6 = new QPushButton(QIcon(QPixmap(":/resources/images/icons8-robotic-50.ico")), "����Ի���", this);

	vBoxLayout_1->addWidget(modal_btn);
	vBoxLayout_1->addWidget(Nonmodal_btn);
	vBoxLayout_1->addWidget(box1);
	vBoxLayout_1->addWidget(box2);
	vBoxLayout_1->addWidget(box3);
	vBoxLayout_1->addWidget(box4);
	vBoxLayout_1->addWidget(box5);
	vBoxLayout_1->addWidget(box6);

	dock->setWidget(btn_group);


	//����í�Ӳ���ͣ��λ��
	dock->setAllowedAreas(Qt::DockWidgetArea_Mask);

	//����һ�����Ĳ���
	QTextEdit* text = new QTextEdit("һ������ѹ�Ǻ�", this);
	this->setCentralWidget(text);

	//���˵������ͼ��
	//ͼƬ�ؼ�,��ԭͼƬ
	QPixmap pix(":/resources/images/manufacturing_01.ico");
	//pix.load(":/resources/images/manufacturing_01.png");
	New->setIcon(QIcon(pix));


	//�Ի���
	//����ģ̬�Ի���
	QDialog* modal_dlg = new QDialog(this);
	modal_dlg->resize(200, 200);
	//��Ϊģ̬��ʾ�Ի���, ����ʹ��open()��ģ̬�Ի���, exec()���ܳ���bug,�����಻��.
	//modal_dlg->open();
	connect(modal_btn, &QPushButton::clicked, modal_dlg, &QDialog::open);

	//��ģ̬�Ի���
	QDialog* Nonmodal_dlg = new QDialog(this);
	Nonmodal_dlg->resize(200, 200);
	//Nonmodal_dlg->show();
	connect(Nonmodal_btn, &QPushButton::clicked, Nonmodal_dlg, &QDialog::show);


	//���öԻ���
	connect(box1, &QPushButton::clicked, [&]()
		{
			QMessageBox::critical(this, "������ʾ��", "���ش���Ŷ! ");
		}
	);
	connect(box2, &QPushButton::clicked, [&]()
		{
			QMessageBox::warning(this, "������ʾ��", "����Ŷ! ");
		}
	);
	connect(box3, &QPushButton::clicked, [&]()
		{
			QMessageBox::information(this, "��Ϣ��ʾ��", "��ϢŶ! ");
		}
	);
	connect(box4, &QPushButton::clicked, [&]()
		{
			qDebug() << QMessageBox::question(this, tr("ѯ����ʾ��"), "ѯ��Ŷ! ");
		}
	);


	//����Ի���
	connect(box6, &QPushButton::clicked, [&]()
		{
			bool yes;
			QFont font;
			font = QFontDialog::getFont(&yes, QFont("����"), this);
			qDebug() << "yes= " << yes;
			if (yes)
			{
				qDebug() << tr("����Ϊ: ") << font.family() << tr("���๦�ܿ����Ա����") << endl;
			}
		}
	);



	//�ļ��Ի���
	connect(box5, &QPushButton::clicked, [&]()
		{
			QString file_name = nullptr;
			file_name = QFileDialog::getOpenFileName(this);
			qDebug() << file_name << endl;
		}
	);
}

MainWindows::~MainWindows()
{
}
