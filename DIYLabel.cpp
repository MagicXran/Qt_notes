#include "DIYLabel.h"
#include <QMouseEvent>
//#include <QEvent>

DIYLabel::DIYLabel(QWidget* parent)
	: QLabel(parent)
{
	//Ҫ���ƶ��¼�,��Ҫ������������,����,���֮�ƶ�������Ҳ�ɱ�׷��.
	this->setMouseTracking(true);
}

void DIYLabel::enterEvent(QEvent* event)
{
	qDebug() << "������" << endl;
}

void DIYLabel::leaveEvent(QEvent* event)
{
	qDebug() << "����Ƴ�" << endl;
}

void DIYLabel::mouseMoveEvent(QMouseEvent* ev)
{
	qDebug() << "�ƶ���" << endl;
	qDebug() << ev->x() << "," << ev->y() << endl;
	qDebug() << ev->globalX() << "," << ev->globalY() << endl;
}

void DIYLabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		qDebug() << "����������\n";
	}
	else if (ev->button() == Qt::RightButton)
	{
		qDebug() << "����Ҽ�����\n";
	}
}

//�¼��ַ���
bool DIYLabel::event(QEvent* e)
{
	//ֻ������갴���¼�
	if (e->type() == QEvent::MouseButtonPress)
	{
		qDebug() << "���¼��ַ�����, �ػ���갴���¼�  ";

		//ǿ��ת��,�Ի��x,y �������
		QMouseEvent* ev = static_cast<QMouseEvent*>(e);
		qDebug() << ev->x() << "," << ev->y() << endl;


		// ���÷ַ������´��ݸ��¼�
		return true;
	}

	//���ø����¼��ַ���,���������¼�, ������������ֻ������갴���¼�,����ʱ���޶���.!!!
	return QLabel::event(e); //DIYLabel�̳���QLabel
}

DIYLabel::~DIYLabel()
{
}
