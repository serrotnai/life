#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamecanvas.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    // Functions called in response to clicked buttons
    void tickMain();
    void loadFileMain();
    void setOriginMain();

private:
    Ui::MainWindow *ui;
    GameCanvas *canvas;
};

#endif // MAINWINDOW_H
