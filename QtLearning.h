#pragma once

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QSharedPointer>
#include "ui_QtLearning.h"

//解决控件显示中文乱码
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

class QtLearning : public QWidget
{
    Q_OBJECT //让QMainWindow支持信号和槽机制, 自定义信号/槽函数也用此.

public:
    QtLearning(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtLearningClass ui;
};
