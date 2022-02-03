#pragma once
#include <QWidget>
#include "ui_EventStudy.h"
#include "common_header.hpp"

class EventStudy : public QWidget
{
	Q_OBJECT

public:
	EventStudy(QWidget *parent = Q_NULLPTR);
	~EventStudy();

private:
	Ui::EventStudy ui;
};
