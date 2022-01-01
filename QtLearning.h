#pragma once
#include "common_header.hpp"
#include <QtWidgets/QWidget>
#include "ui_QtLearning.h"


class QtLearning : public QWidget
{
    Q_OBJECT; //让QMainWindow支持信号和槽机制, 自定义信号/槽函数也用此.

public:
    QtLearning(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtLearningClass ui;
};
