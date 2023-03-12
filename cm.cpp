#include "cm.h"
#include "QTimer"
#include<QProgressBar>
#include <QDebug>

CM::CM(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.log_text->setReadOnly(true);
	ui.log_text->setLineWrapMode(QTextEdit::WidgetWidth);

	//QTimer* timer = new QTimer(this);
	/*int i = 1;
	connect(timer, &QTimer::timeout, [&]() {
		i++;
		ui.log_text->append(QString::number(i));
		});
	timer->start(1000);*/

	QProgressBar* progressBar = new QProgressBar(this);
	QTimer* myTimer = new QTimer(this);            //计时器对象
	progressBar->resize(400, 40);
	progressBar->setMaximum(100);
	progressBar->setMinimum(0);
	progressBar->setValue(0);
	prog_num = 0;

	connect(myTimer, &QTimer::timeout, [=]()
		{
			++prog_num;
			qDebug() << prog_num;
			if (prog_num > 20)
			{
				myTimer->stop();	                    //停止计时器
			}
			ui.log_text->append(QString::number(prog_num));
			progressBar->setValue(prog_num * 5);
			progressBar->setWindowModality(Qt::WindowModal);

		});  //将超时信号和自定义的槽函数连接
	myTimer->start(100);					//设置超时时间为000ms，启动计时器
}

CM::~CM()
{
}

void CM::redner()
{
	ui.log_text->append(tr("this test"));
}
