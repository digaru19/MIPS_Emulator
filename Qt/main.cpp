#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include "instructions.h"
#include "datapath_elements.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
