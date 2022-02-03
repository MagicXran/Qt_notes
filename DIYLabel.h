#pragma once

#include <QLabel>
#include "common_header.hpp"

class DIYLabel : public QLabel
{
	Q_OBJECT

public:
	DIYLabel(QWidget* parent = 0);

	//��д�������¼�
	virtual void enterEvent(QEvent* event);
	//��д����뿪�¼�
	virtual void leaveEvent(QEvent* event);

	//override ����ƶ�
	virtual void mouseMoveEvent(QMouseEvent* ev);
	//override ��갴���¼�
	virtual void mousePressEvent(QMouseEvent* ev);

	//��д�¼��ַ���
	virtual bool event(QEvent* e);
	~DIYLabel();
};
