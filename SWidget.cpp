#include "SWidget.h"

SWidget::SWidget(QWidget* parent /*= Q_NULLPTR*/)
{
	this->resize(800, 600);
	this->setWindowTitle("��ѯ����");

	QPushButton* back_btn = new QPushButton("����", this);
	connect(back_btn, &QPushButton::clicked, [=]()
		{
			emit this->back();
		}
	);
}
