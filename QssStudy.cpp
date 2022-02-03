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

	//������ʽ��
	QString qss;
	QFile file(cssStr);

	if (file.open(QFile::ReadOnly))
	{
		//��readAll��ȡĬ��֧�ֵ���ANSI��ʽ
		//�����С����creator�򿪱༭���˺ܿ��ܴ򲻿�
		//qss = QLatin1String(file.readAll());

		//QString paletteColor = qss.mid(20, 7);
		//qApp->setPalette(QPalette(QColor(paletteColor)));
		//qApp->setStyleSheet(qss);
		qApp->setStyleSheet(file.readAll());
		file.close();
	}
}
