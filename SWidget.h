#pragma once
#include <qwidget.h>
#include <QPushButton>
#include "common_header.hpp"
class SWidget :
    public QWidget
{
	Q_OBJECT; //��QMainWindow֧���źźͲۻ���, �Զ����ź�/�ۺ���Ҳ�ô�.

public:
	SWidget(QWidget* parent = Q_NULLPTR);

signals:
	void back();//�����ź�
};

