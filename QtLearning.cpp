#include "QtLearning.h"
#include "Teacher.h"
#include "Student.h"

#define  N  3
QtLearning::QtLearning(QWidget* parent)
	: QWidget(parent)
{
	// this ��ʾ������
	ui.setupUi(this);

	this->setWindowTitle("���߰���");
	//this->setFixedSize(800, 600);

	auto btn1 = new QPushButton("�ر�", this);
	//auto qptr = QSharedPointer<QPushButton>(new QPushButton("��һ��", this));
	//qptr->get()->setParent(this);


	/*auto qpb_ptr = std::make_shared<QPushButton>("����");
	qpb_ptr->setParent(this);

	auto b1 = QSharedPointer<QPushButton>(new QPushButton("Qpָ��"));
	b1->setParent(this);*/

	QPushButton* b2 = new QPushButton("�¿�", this);
	b2->move(400, 300);

	//singal- slot
	connect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);
	b2->disconnect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);
	//lambda
	connect(btn1, &QPushButton::clicked, [=] {
		QString text = btn1->text();
		qDebug() << text << "�Ұ���dd" << endl; //ʹ��QDbug�Դ�endl

		std::cout << "heee �Ұ���" << std::endl; //����
		});


	//auto b3 = new QPushButton("b3��", this);
	this->resize(600, 400);

	/// <summary>
	/// �Զ����ź�/�ۺ���
	/// </summary>
	/// <param name="parent"></param>
	Teacher* tea = new Teacher(this);
	Student* stu = new Student(this);


#if  (N == 0) || (N == 3)
	//������ϵ
	void (Teacher:: * func_ptr)() = &Teacher::hungry;
	void (Student:: * treat_ptr)() = &Student::treat;
	//connect(tea, &Teacher::hungry, stu, &Student::treat);
	connect(tea, func_ptr, stu, treat_ptr);

#else (N == 1)
	void (Teacher:: * func_ptr)(QString) = &Teacher::hungry;
	void (Student:: * treat_ptr)(QString) = &Student::treat;
	connect(tea, func_ptr, stu, treat_ptr);
#endif

#if (N == 0)
	//�¿���ʦ�Ͷ���,ͨ����ť��ʾ
	connect(b2, &QPushButton::clicked, [=] {
		//�¿�, �����ź�!
		emit tea->hungry();
		});
#else (N == 1)
	//�¿���ʦ�Ͷ���,ͨ����ť��ʾ
	connect(b2, &QPushButton::clicked, [=] {
		//�¿�, �����ź�!
		emit tea->hungry("������");
		});
#endif

#if (N == 3) 
	//�ź������ź�
	connect(b2, &QPushButton::clicked, tea, func_ptr);
#endif

}
