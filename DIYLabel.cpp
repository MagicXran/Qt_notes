#include "DIYLabel.h"
#include <QMouseEvent>
//#include <QEvent>

DIYLabel::DIYLabel(QWidget* parent)
	: QLabel(parent)
{
	//要想移动事件,需要先启用鼠标跟踪,这样,鼠标之移动不按键也可被追踪.
	this->setMouseTracking(true);
}

void DIYLabel::enterEvent(QEvent* event)
{
	qDebug() << "鼠标进入" << endl;
}

void DIYLabel::leaveEvent(QEvent* event)
{
	qDebug() << "鼠标移出" << endl;
}

void DIYLabel::mouseMoveEvent(QMouseEvent* ev)
{
	qDebug() << "移动了" << endl;
	qDebug() << ev->x() << "," << ev->y() << endl;
	qDebug() << ev->globalX() << "," << ev->globalY() << endl;
}

void DIYLabel::mousePressEvent(QMouseEvent* ev)
{
	if (ev->button() == Qt::LeftButton)
	{
		qDebug() << "鼠标左键按下\n";
	}
	else if (ev->button() == Qt::RightButton)
	{
		qDebug() << "鼠标右键按下\n";
	}
}

//事件分发器
bool DIYLabel::event(QEvent* e)
{
	//只关心鼠标按下事件
	if (e->type() == QEvent::MouseButtonPress)
	{
		qDebug() << "在事件分发器中, 截获鼠标按下事件  ";

		//强制转型,以获得x,y 坐标参数
		QMouseEvent* ev = static_cast<QMouseEvent*>(e);
		qDebug() << ev->x() << "," << ev->y() << endl;


		// 不让分发器向下传递该事件
		return true;
	}

	//调用父类事件分发器,处理其他事件, 否则上述代码只处理鼠标按下事件,其余时间无动作.!!!
	return QLabel::event(e); //DIYLabel继承于QLabel
}

DIYLabel::~DIYLabel()
{
}
