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
	/// 透明度: 从0自动加载到98; connect: 关联文本和progressBar
	/// </summary>
	void test_opacity();


	/// <summary>
	/// 动画
	/// </summary>
	void test_animation();
private:
	Ui::animation ui;
};
