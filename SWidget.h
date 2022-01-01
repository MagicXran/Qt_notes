#pragma once
#include <qwidget.h>
#include <QPushButton>
#include "common_header.hpp"
class SWidget :
    public QWidget
{
	Q_OBJECT; //让QMainWindow支持信号和槽机制, 自定义信号/槽函数也用此.

public:
	SWidget(QWidget* parent = Q_NULLPTR);

signals:
	void back();//回退信号
};

