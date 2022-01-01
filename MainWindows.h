#pragma once

#include <QMainWindow>
//#include "ui_MainWindow.h"
#include "ui_MainInterface.h"

#include "common_header.hpp"

class MainWindows : public QMainWindow
{
	Q_OBJECT

public:
	MainWindows(QWidget* parent = 0);
	~MainWindows();

private:
	Ui::MainWindow ui;
};
