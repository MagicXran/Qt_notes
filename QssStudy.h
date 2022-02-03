#pragma once
#include <QWidget>
#include "ui_QssStudy.h"
#include "common_header.hpp"
class QssStudy : public QWidget
{
	Q_OBJECT

public:
	QssStudy(QWidget *parent = Q_NULLPTR);
	~QssStudy();

	void setOpacity();


private:
	void initQssStyle(QColor);
	Ui::QssStudy ui;
};
