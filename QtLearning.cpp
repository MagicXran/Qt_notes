#include "QtLearning.h"
#include<QDebug>
#include <iostream>

QtLearning::QtLearning(QWidget* parent)
	: QWidget(parent)
{
	// this 表示主窗口
	ui.setupUi(this);

	this->setWindowTitle("仁者爱人");
	//this->setFixedSize(800, 600);

	auto btn1 = new QPushButton("关闭", this);
	//auto qptr = QSharedPointer<QPushButton>(new QPushButton("第一个", this));
	//qptr->get()->setParent(this);


	/*auto qpb_ptr = std::make_shared<QPushButton>("二货");
	qpb_ptr->setParent(this);

	auto b1 = QSharedPointer<QPushButton>(new QPushButton("Qp指针"));
	b1->setParent(this);*/

	QPushButton* b2 = new QPushButton("最大化窗口", this);
	b2->move(400, 300);

	//singal- slot
	connect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);

	//lambda
	connect(btn1, &QPushButton::clicked, [=] {
		QString text = btn1->text();
		qDebug() << text << "我爱你dd" << endl;
		std::cout << "heee 我爱你" << std::endl;
		});


	//auto b3 = new QPushButton("b3了", this);
	this->resize(600, 400);


}
