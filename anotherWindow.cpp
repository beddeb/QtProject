#include "anotherwindow.h"
#include "./ui_anotherwindow.h"

AnotherWindow::AnotherWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnotherWindow)
{
    ui->setupUi(this);
    QPixmap newpix("-");
    QPixmap openpix("-");
    QPixmap quitpix("C:/Users/1/Documents/AnotherWindow/open.png");

    QAction *newa = new QAction(newpix, "&New", this);
    QAction *open = new QAction(openpix, "&Open", this);
    QAction *quit = new QAction(quitpix, "&Shutdown", this);


    quit->setShortcut(tr("CTRL+Q"));

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(newa);
    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}

AnotherWindow::~AnotherWindow()
{
    delete ui;
}
