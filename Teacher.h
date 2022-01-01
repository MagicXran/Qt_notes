#pragma once
#include "common_header.hpp"
#include <QObject>
class Teacher :
	public QObject
{
	Q_OBJECT;
public:
	explicit Teacher(QObject* parent = 0);

signals:	//自定义信号函数
	//定义信号规则: 
	//返回值类型void 
	//只声明不实现
	// 可以有参数,可重载
	void hungry();
	void hungry(QString food_name);

public slots: //自定义槽函数

};

