#include "QssStudy.h"
#include "QFile"
#include <QPropertyAnimation> 
#include <QGraphicsOpacityEffect> 


QssStudy::QssStudy(QWidget* parent)
	: QWidget(parent)
{
	initQssStyle(Qt::red);
}



QssStudy::~QssStudy()
{
}


void QssStudy::initQssStyle(QColor color)
{
	QString cssStr;
	cssStr = ":/resources/QssStyle/qss01.qss";

	//加载样式表
	QString qss;
	QFile file(cssStr);

	if (file.open(QFile::ReadOnly))
	{
		//用readAll读取默认支持的是ANSI格式
		//如果不小心用creator打开编辑过了很可能打不开
		//qss = QLatin1String(file.readAll());

		//QString paletteColor = qss.mid(20, 7);
		//qApp->setPalette(QPalette(QColor(paletteColor)));
		//qApp->setStyleSheet(qss);
		qApp->setStyleSheet(file.readAll());
		file.close();
	}
}
