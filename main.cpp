#include "QtLearning.h"
#include <QtWidgets/QApplication>
#include "MainWindows.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QtLearning w;
    MainWindows w;
    w.show();

    return a.exec();
}
