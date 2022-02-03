#include "Layout.h"
#include "ui_Layout.h"

Layout::Layout(QWidget* parent)
	: QWidget(parent)
{
	ui = new Ui::Layout();
	ui->setupUi(this);

	this->resize(800, 500);
	//��ѡ��
	//Ĭ��ѡ��: ��-δ��
	ui->man_radio_btn->setChecked(true);
	ui->unmarried_radio_btn->setChecked(true);

	//�ź��¼�
	connect(ui->woman_radio_btn, &QRadioButton::clicked, [&]()
		{
			//�ж�radio buttton �Ƿ�ѡ��
			qDebug() << ui->woman_radio_btn->isChecked() << endl;
		}
	);

	//list widget
	connect(ui->list_widget, &QListWidget::itemClicked, [](QListWidgetItem* item)
		{
			//��ȡѡ�е�item
			qDebug() << item->text() << endl;
		}
	);


	//tree widget
	//set header items
	ui->treeWidget->setHeaderLabels(QStringList() << "����" << "����");
	//add top items
	auto items1 = new QTreeWidgetItem(QStringList() << "С��Ů" << "12");
	auto items2 = new QTreeWidgetItem(QStringList() << "������");
	ui->treeWidget->addTopLevelItem(items1);
	ui->treeWidget->addTopLevelItem(items2);

	//add child item to top item
	items1->addChild(new QTreeWidgetItem(QStringList() << "�Ҽ�С��Ů" << "14"));
	items2->addChild(new QTreeWidgetItem(QStringList() << "����_��ʥ" << "144"));
	items2->setSelected(true);
	//������
	connect(ui->treeWidget, &QTreeWidget::itemClicked, [](QTreeWidgetItem* treeItem, int column)
		{
			qDebug() << "column: " << column << "item text: " << treeItem->text(column).toUtf8().data() << endl;
		}
	);


	//table widget 
	//set row/column nums [5,3]
	ui->tableWidget->setRowCount(5);
	ui->tableWidget->setColumnCount(3);

	//���ñ�ͷ��Ϣ
	ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "ˮƽ��ͷ1" << "ˮƽ��ͷ2" << "ˮƽ��ͷ3");

	//��table ��ӿؼ�
	QStringList name, sex;
	name << "�ŷ�" << "С��Ů" << "��Ҳһ��";
	sex << "��" << "Ů" << "����";

	for (int i = 0; i < name.length(); ++i)
	{
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name[i]));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(sex[i]));
		//int -> QString
		ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(i + 20)));
	}

	//������ɫ
	QRadialGradient gradient(50, 50, 50, 50, 50);
	gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
	gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

	QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(200));
	item3->setBackground(QBrush(Qt::TexturePattern));
	//[3,1]
	ui->tableWidget->setItem(3, 1, item3);

	//������
	connect(ui->tableWidget, &QTableWidget::itemClicked,
		[=](QTableWidgetItem* item)
		{
			qDebug() << "[row,column]=[" << item->row() << ", " <<
				item->column() << "]" << "content: " << item->text().toUtf8().data() << endl;
		}
	);
}

Layout::~Layout()
{
	delete ui;
}
