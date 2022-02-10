#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.resize(400, 400);
    w.setWindowTitle("GitHub");

    w.show();
    return app.exec();
}
