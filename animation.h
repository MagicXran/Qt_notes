#pragma once

#include <QWidget>
#include "ui_animation.h"
#include "common_header.hpp"

class animation : public QWidget
{
	Q_OBJECT

public:
	animation(QWidget* parent = Q_NULLPTR);
	~animation();

	/// <summary>
	/// ͸����: ��0�Զ����ص�98; connect: �����ı���progressBar
	/// </summary>
	void test_opacity();


	/// <summary>
	/// ����
	/// </summary>
	void test_animation();
private:
	Ui::animation ui;
};
