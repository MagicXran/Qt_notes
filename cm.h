#pragma once

#include <QMainWindow>
#include "ui_cm.h"

class CM : public QMainWindow
{
	Q_OBJECT

public:
	CM(QWidget *parent = Q_NULLPTR);
	~CM();

private:
	Ui::CM ui;
};
