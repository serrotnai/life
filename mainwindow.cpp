#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canvas(new GameCanvas(this))
{
    ui->setupUi(this);

    connect(ui->tickButton, SIGNAL(clicked()), this, SLOT(tickMain()));
    connect(ui->loadFileButton, SIGNAL(clicked()), this, SLOT(loadFileMain()));
    connect(ui->setOriginButton, SIGNAL(clicked()), this, SLOT(setOriginMain()));

    ui->gameLayout->addWidget(canvas);
    canvas->setMinimumSize(640, 640);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}

void MainWindow::tickMain()
{
    canvas->tick();
}

void MainWindow::loadFileMain()
{
    QString filename = ui->fileNameEdit->text();
    canvas->loadFile(filename);
}

void MainWindow::setOriginMain()
{
    long long x = ui->xOriginEdit->text().toLongLong();
    long long y = ui->yOriginEdit->text().toLongLong();
    canvas->setOrigin(x, y);
}
