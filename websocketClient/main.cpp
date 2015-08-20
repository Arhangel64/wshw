#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName("INITI");
    a.setOrganizationDomain("initi.ru");
    a.setApplicationName("High Society");
    MainWindow w(0);
    w.show();

    return a.exec();
}
