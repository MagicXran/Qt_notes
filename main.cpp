#include <QtWidgets/QApplication>
//#include "QtLearning.h"
//#include "MainWindows.h"
//#include "Layout.h"
#include "EventStudy.h"
//#include "QssStudy.h"
//#include "animation.h"
#include "cm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QtLearning w;
    //MainWindows w;
    //Layout w;
    //EventStudy w;
    //QssStudy w;
    //animation w;
    CM w;
    w.show();

    return a.exec();
}
