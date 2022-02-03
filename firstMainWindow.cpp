#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Создаем объект класса QAction c названием quit
    QAction *quit = new QAction("&Quit", this);

    //Создаем объект класса Qmenu
    QMenu *file;
    file = menuBar()->addMenu("&File");

    //Помещаем наше действие в наш виджет qmain с помощью метода addaction()
    file->addAction(quit);

    //Когда выбираем quit, срабатывает триггер выхода QApplication::quit
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

