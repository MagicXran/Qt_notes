#include "animation.h"
#include "QGraphicsEffect"
#include "QPropertyAnimation"
#include "QPushButton"

animation::animation(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->resize(800, 600);
	//ui.scale_btn->resize(100, 50);
	//ui.displacement_btn->resize(100, 50);

	//透明效果
	//test_opacity();

	test_animation();

}

animation::~animation()
{
}

void animation::test_opacity()
{
	//实例QGraphicsOpacityEffect
	QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(this);

	//设定透明值
	effect->setOpacity(0.8);


	//slider_text 文本框 透明度设置
	//ui.slider_text->setGraphicsEffect(effect);
	this->setGraphicsEffect(effect);

	//拖动滑条,实时显示其值于文本框中.
	connect(ui.horizontalSlider, &QSlider::valueChanged, [=](int value)
		{
			ui.slider_text->setText(QVariant(value).toString());
			ui.progressBar->setValue(value);
			//设置窗口的透明度
			//this->setWindowOpacity((qreal)(value / 100.0));
		}
	);

}

void animation::test_animation()
{
	//缩放
	QPropertyAnimation* pScaleAnimation1 = new QPropertyAnimation(ui.scale_btn, "geometry");

	QRect pos{ ui.scale_btn->geometry() };

	connect(ui.scale_btn, &QPushButton::clicked, [=]()
		{
			pScaleAnimation1->setDuration(3000); //动画时长3s
			pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
			pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));
			//pScaleAnimation1->setKeyValueAt(0, QRect(0, 0, 100, 30));
			//pScaleAnimation1->setKeyValueAt(0.8, QRect(250, 250, 100, 30));
			//pScaleAnimation1->setKeyValueAt(1, pos);
			pScaleAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
			pScaleAnimation1->start(QAbstractAnimation::DeleteWhenStopped);
		}
	);


	//位移
	QPropertyAnimation* pPosAnimation1 = new QPropertyAnimation(ui.displacement_btn, "pos");
	QRect pos_{ ui.displacement_btn->geometry() };
	connect(ui.displacement_btn, &QPushButton::clicked, [=]()
		{
			pPosAnimation1->setDuration(2000);
			pPosAnimation1->setStartValue(QPoint(360, 160));
			pPosAnimation1->setKeyValueAt(1,pos_);
			pPosAnimation1->setEndValue(pos_);
			//pPosAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
			pPosAnimation1->start(QAbstractAnimation::DeleteWhenStopped);
		}
	);

	//并行动画


}

