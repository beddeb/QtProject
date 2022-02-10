#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap newpix("-");
    QPixmap openpix("-");
    QPixmap quitpix("-");

    QAction *newa = new QAction(newpix, "&New", this);
    QAction *open = new QAction(openpix, "&Open", this);
    QAction *quit = new QAction(quitpix, "&Shutdown", this);

    m_button = new QPushButton("Get Brain", this);
    m_button->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));

    quit->setShortcut(tr("CTRL+Q"));

    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(newa);
    file->addAction(open);
    file->addSeparator();
    file->addAction(quit);

    qApp->setAttribute(Qt::AA_DontShowIconsInMenus, false);

    connect(quit, &QAction::triggered, qApp, &QApplication::quit);
    connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));
}

void MainWindow::handleButton(){

    m_button->setText("Buy NoRender");
    m_button->resize(100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
