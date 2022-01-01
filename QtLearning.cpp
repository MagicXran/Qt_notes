#include "QtLearning.h"
#include "Teacher.h"
#include "Student.h"

#define  N  3
QtLearning::QtLearning(QWidget* parent)
	: QWidget(parent)
{
	// this 表示主窗口
	ui.setupUi(this);

	this->setWindowTitle("仁者爱人");
	//this->setFixedSize(800, 600);

	auto btn1 = new QPushButton("关闭", this);
	//auto qptr = QSharedPointer<QPushButton>(new QPushButton("第一个", this));
	//qptr->get()->setParent(this);


	/*auto qpb_ptr = std::make_shared<QPushButton>("二货");
	qpb_ptr->setParent(this);

	auto b1 = QSharedPointer<QPushButton>(new QPushButton("Qp指针"));
	b1->setParent(this);*/

	QPushButton* b2 = new QPushButton("下课", this);
	b2->move(400, 300);

	//singal- slot
	connect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);
	b2->disconnect(b2, &QPushButton::clicked, this, &QWidget::showFullScreen);
	//lambda
	connect(btn1, &QPushButton::clicked, [=] {
		QString text = btn1->text();
		qDebug() << text << "我爱你dd" << endl; //使用QDbug自带endl

		std::cout << "heee 我爱你" << std::endl; //乱码
		});


	//auto b3 = new QPushButton("b3了", this);
	this->resize(600, 400);

	/// <summary>
	/// 自定义信号/槽函数
	/// </summary>
	/// <param name="parent"></param>
	Teacher* tea = new Teacher(this);
	Student* stu = new Student(this);


#if  (N == 0) || (N == 3)
	//建立关系
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
	//下课老师就饿了,通过按钮表示
	connect(b2, &QPushButton::clicked, [=] {
		//下课, 发出信号!
		emit tea->hungry();
		});
#else (N == 1)
	//下课老师就饿了,通过按钮表示
	connect(b2, &QPushButton::clicked, [=] {
		//下课, 发出信号!
		emit tea->hungry("锅包肉");
		});
#endif

#if (N == 3) 
	//信号连接信号
	connect(b2, &QPushButton::clicked, tea, func_ptr);
#endif

}
