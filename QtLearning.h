#pragma once
#include "common_header.hpp"
#include <QtWidgets/QWidget>
#include "ui_QtLearning.h"


class QtLearning : public QWidget
{
    Q_OBJECT; //��QMainWindow֧���źźͲۻ���, �Զ����ź�/�ۺ���Ҳ�ô�.

public:
    QtLearning(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtLearningClass ui;
};
