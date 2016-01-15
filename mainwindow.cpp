#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    canvas(new GameCanvas(this))
{
    ui->setupUi(this);

    // Set up signals and slots
    connect(ui->loadFileButton, SIGNAL(clicked()), this, SLOT(loadFileMain()));
    connect(ui->setOriginButton, SIGNAL(clicked()), this, SLOT(setOriginMain()));
    connect(ui->tickButton, SIGNAL(clicked()), canvas, SLOT(tick()));
    connect(ui->animateButton, SIGNAL(clicked()), canvas, SLOT(animate()));
    connect(ui->pauseButton, SIGNAL(clicked()), canvas, SLOT(pause()));
    connect(ui->sizeSlider, SIGNAL(valueChanged(int)), canvas, SLOT(setSize(int)));
    connect(ui->speedSlider, SIGNAL(valueChanged(int)), canvas, SLOT(setSpeed(int)));

    // Add game canvas to window
    ui->gameLayout->addWidget(canvas);
    canvas->setMinimumSize(640, 640);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete canvas;
}

void MainWindow::loadFileMain()
{
    QString filename = "res/" + ui->fileNameEdit->text();
    canvas->loadFile(filename);
}

void MainWindow::setOriginMain()
{
    long long x = ui->xOriginEdit->text().toLongLong();
    long long y = ui->yOriginEdit->text().toLongLong();
    canvas->setOrigin(x, y);
}
