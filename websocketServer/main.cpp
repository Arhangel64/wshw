#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("INITI");
    a.setOrganizationDomain("initi.ru");
    a.setApplicationName("High society server");
    MainWindow w;
    w.show();

    return a.exec();
}
