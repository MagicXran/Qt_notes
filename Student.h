#pragma once
#include "common_header.hpp"
#include <QObject>
class Student :
	public QObject
{
	Q_OBJECT
public:
	explicit Student(QObject* parent = 0);

signals:

public slots: //自定义槽函数
	//规则:
	//返回值类型void
	//需声明不实现, 需要实现
	//可以有参数,可重载
	void treat();
	void treat(QString food_name);

};

