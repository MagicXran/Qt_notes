#include "QtLearning.h"
#include<QDebug>
#include <iostream>

QtLearning::QtLearning(QWidget* parent)
	: QWidget(parent)
{
	// this ��ʾ������
	ui.setupUi(this);

	this->setWindowTitle("���߰���");
	//this->setFixedSize(800, 600);

	auto btn1 = new QPushButton("�ر�", this);
	//auto qptr = QSharedPointer<QPushButton>(new QPushButton("��һ��", this));
	//qptr->get()->setParent(this);


	/*auto qpb_ptr = std::make_shared<QPushButton>("����");
	qpb_ptr->setParent(this);

	auto b1 = QSharedPointer<QPushButton>(new QPushButton("Qpָ��"));
	b1->setParent(this);*/

	QPushButton* b2 = new QPushButton("��󻯴���", this);
	b2->move(400, 300);

	//singal- slot
	connect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);

	//lambda
	connect(btn1, &QPushButton::clicked, [=] {
		QString text = btn1->text();
		qDebug() << text << "�Ұ���dd" << endl;
		std::cout << "heee �Ұ���" << std::endl;
		});


	//auto b3 = new QPushButton("b3��", this);
	this->resize(600, 400);


}
