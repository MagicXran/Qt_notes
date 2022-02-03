#pragma once
#include "common_header.hpp"
#include <QWidget>
namespace Ui { class Layout; };

class Layout : public QWidget
{
	Q_OBJECT

public:
	Layout(QWidget *parent = Q_NULLPTR);
	~Layout();

private:
	Ui::Layout *ui;
};
