#include "Student.h"

Student::Student(QObject* parent /*= 0*/)
{

}

void Student::treat()
{
	qDebug() << "�����ʦ!" << endl;
}

void Student::treat(QString food_name)
{
	qDebug() << "�����ʦ! ��:" << food_name << endl;
}
