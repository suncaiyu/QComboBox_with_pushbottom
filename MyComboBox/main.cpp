#include "MainWindow.h"
#include <QApplication>
#include "FFFFF.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FFFFF w;
    w.show();

    return a.exec();
}
