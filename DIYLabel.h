#pragma once

#include <QLabel>
#include "common_header.hpp"

class DIYLabel : public QLabel
{
	Q_OBJECT

public:
	DIYLabel(QWidget* parent = 0);

	//重写鼠标进入事件
	virtual void enterEvent(QEvent* event);
	//重写鼠标离开事件
	virtual void leaveEvent(QEvent* event);

	//override 鼠标移动
	virtual void mouseMoveEvent(QMouseEvent* ev);
	//override 鼠标按下事件
	virtual void mousePressEvent(QMouseEvent* ev);

	//重写事件分发器
	virtual bool event(QEvent* e);
	~DIYLabel();
};
