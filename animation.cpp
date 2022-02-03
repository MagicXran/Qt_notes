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

	//͸��Ч��
	//test_opacity();

	test_animation();

}

animation::~animation()
{
}

void animation::test_opacity()
{
	//ʵ��QGraphicsOpacityEffect
	QGraphicsOpacityEffect* effect = new QGraphicsOpacityEffect(this);

	//�趨͸��ֵ
	effect->setOpacity(0.8);


	//slider_text �ı��� ͸��������
	//ui.slider_text->setGraphicsEffect(effect);
	this->setGraphicsEffect(effect);

	//�϶�����,ʵʱ��ʾ��ֵ���ı�����.
	connect(ui.horizontalSlider, &QSlider::valueChanged, [=](int value)
		{
			ui.slider_text->setText(QVariant(value).toString());
			ui.progressBar->setValue(value);
			//���ô��ڵ�͸����
			//this->setWindowOpacity((qreal)(value / 100.0));
		}
	);

}

void animation::test_animation()
{
	//����
	QPropertyAnimation* pScaleAnimation1 = new QPropertyAnimation(ui.scale_btn, "geometry");

	QRect pos{ ui.scale_btn->geometry() };

	connect(ui.scale_btn, &QPushButton::clicked, [=]()
		{
			pScaleAnimation1->setDuration(3000); //����ʱ��3s
			pScaleAnimation1->setStartValue(QRect(190, 230, 0, 0));
			pScaleAnimation1->setEndValue(QRect(120, 160, 140, 140));
			//pScaleAnimation1->setKeyValueAt(0, QRect(0, 0, 100, 30));
			//pScaleAnimation1->setKeyValueAt(0.8, QRect(250, 250, 100, 30));
			//pScaleAnimation1->setKeyValueAt(1, pos);
			pScaleAnimation1->setEasingCurve(QEasingCurve::InOutQuad);
			pScaleAnimation1->start(QAbstractAnimation::DeleteWhenStopped);
		}
	);


	//λ��
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

	//���ж���


}

