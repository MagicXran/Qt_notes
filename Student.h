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

public slots: //�Զ���ۺ���
	//����:
	//����ֵ����void
	//��������ʵ��, ��Ҫʵ��
	//�����в���,������
	void treat();
	void treat(QString food_name);

};

