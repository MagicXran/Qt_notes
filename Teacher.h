#pragma once
#include "common_header.hpp"
#include <QObject>
class Teacher :
	public QObject
{
	Q_OBJECT;
public:
	explicit Teacher(QObject* parent = 0);

signals:	//�Զ����źź���
	//�����źŹ���: 
	//����ֵ����void 
	//ֻ������ʵ��
	// �����в���,������
	void hungry();
	void hungry(QString food_name);

public slots: //�Զ���ۺ���

};

