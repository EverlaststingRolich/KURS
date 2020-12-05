#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include "luggage.h"
#include "cargo.h"
#include "collection.h"




int main(int argc, char *argv[])
{
    using namespace std;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
