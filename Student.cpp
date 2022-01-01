#include "Student.h"

Student::Student(QObject* parent /*= 0*/)
{

}

void Student::treat()
{
	qDebug() << "款待老师!" << endl;
}

void Student::treat(QString food_name)
{
	qDebug() << "款待老师! 吃:" << food_name << endl;
}
