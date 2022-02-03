#include "Layout.h"
#include "ui_Layout.h"

Layout::Layout(QWidget* parent)
	: QWidget(parent)
{
	ui = new Ui::Layout();
	ui->setupUi(this);

	this->resize(800, 500);
	//单选框
	//默认选中: 男-未婚
	ui->man_radio_btn->setChecked(true);
	ui->unmarried_radio_btn->setChecked(true);

	//信号事件
	connect(ui->woman_radio_btn, &QRadioButton::clicked, [&]()
		{
			//判断radio buttton 是否被选中
			qDebug() << ui->woman_radio_btn->isChecked() << endl;
		}
	);

	//list widget
	connect(ui->list_widget, &QListWidget::itemClicked, [](QListWidgetItem* item)
		{
			//获取选中的item
			qDebug() << item->text() << endl;
		}
	);


	//tree widget
	//set header items
	ui->treeWidget->setHeaderLabels(QStringList() << "姓名" << "年龄");
	//add top items
	auto items1 = new QTreeWidgetItem(QStringList() << "小仙女" << "12");
	auto items2 = new QTreeWidgetItem(QStringList() << "无名氏");
	ui->treeWidget->addTopLevelItem(items1);
	ui->treeWidget->addTopLevelItem(items2);

	//add child item to top item
	items1->addChild(new QTreeWidgetItem(QStringList() << "我家小仙女" << "14"));
	items2->addChild(new QTreeWidgetItem(QStringList() << "无名_剑圣" << "144"));
	items2->setSelected(true);
	//动起来
	connect(ui->treeWidget, &QTreeWidget::itemClicked, [](QTreeWidgetItem* treeItem, int column)
		{
			qDebug() << "column: " << column << "item text: " << treeItem->text(column).toUtf8().data() << endl;
		}
	);


	//table widget 
	//set row/column nums [5,3]
	ui->tableWidget->setRowCount(5);
	ui->tableWidget->setColumnCount(3);

	//设置表头信息
	ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "水平表头1" << "水平表头2" << "水平表头3");

	//向table 添加控件
	QStringList name, sex;
	name << "张飞" << "小仙女" << "俺也一样";
	sex << "男" << "女" << "中性";

	for (int i = 0; i < name.length(); ++i)
	{
		ui->tableWidget->setItem(i, 0, new QTableWidgetItem(name[i]));
		ui->tableWidget->setItem(i, 1, new QTableWidgetItem(sex[i]));
		//int -> QString
		ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(i + 20)));
	}

	//背景颜色
	QRadialGradient gradient(50, 50, 50, 50, 50);
	gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
	gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

	QTableWidgetItem* item3 = new QTableWidgetItem(QString::number(200));
	item3->setBackground(QBrush(Qt::TexturePattern));
	//[3,1]
	ui->tableWidget->setItem(3, 1, item3);

	//动起来
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
