#pragma once

#include <QtWidgets/QWidget>
#include <QPushButton>
#include <QSharedPointer>
#include "ui_QtLearning.h"

//����ؼ���ʾ��������
#ifdef WIN32
#pragma execution_character_set("utf-8")
#endif

class QtLearning : public QWidget
{
    Q_OBJECT //��QMainWindow֧���źźͲۻ���, �Զ����ź�/�ۺ���Ҳ�ô�.

public:
    QtLearning(QWidget *parent = Q_NULLPTR);

private:
    Ui::QtLearningClass ui;
};
