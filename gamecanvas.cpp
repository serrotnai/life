#include "gamecanvas.h"
#include <QPainter>
#include <QColor>
#include <QRectF>
#include <QLineF>
#include <QFile>
#include <QTextStream>

#include <QtDebug>

GameCanvas::GameCanvas(QWidget *parent) :
    QWidget(parent),
    m_originX(0),
    m_originY(0),
    m_worldSize(50)
{

}

void GameCanvas::loadFile(QString filename)
{
    m_cells.clear(); // Reset canvas before loading new file
    QFile input(filename);
    input.open(QIODevice::ReadOnly);

    while (!input.atEnd()) {
        QString line = input.readLine().simplified();
        QStringList coords = line.split(" ");
        long long x = coords[0].toLongLong();
        long long y = coords[1].toLongLong();
        m_cells.insert(Cell(x, y));
    }

    input.close();
    update();
}

void GameCanvas::setOrigin(long long x, long long y)
{
    m_originX = x;
    m_originY = y;
    update();
}

long long GameCanvas::getOriginX()
{
    return m_originX;
}


long long GameCanvas::getOriginY()
{
    return m_originY;
}

void GameCanvas::tick()
{
    std::unordered_set<Cell> candidates;
    // Add all current live cells and neighbors to candidates & keep track of counts
    for (Cell cell : m_cells)
    {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                long long x = cell.getX() + i;
                long long y = cell.getY() + j;
                Cell newCell(x, y);
                auto found = candidates.find(newCell);
                if (found != candidates.end()) {
                    if (i != 0 || j != 0) found->m_count++;
                } else {
                    if (i != 0 || j != 0) newCell.m_count++;
                    candidates.insert(newCell);
                }
            }
        }
    }
    // Set m_cells to next generation
    std::unordered_set<Cell> oldCells = m_cells;
    m_cells.clear();
    for (Cell cell : candidates)
    {
        if (cell.m_count == 3 || (cell.m_count == 2 && oldCells.find(cell) != oldCells.end())) {
            addCell(cell.getX(), cell.getY());
        }
    }
    update();
}

void GameCanvas::addCell(long long x, long long y)
{
    m_cells.insert(Cell(x, y));
    update();
}

void GameCanvas::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    // Paint blank canvas and grid lines
    QRect bounds(0, 0, width() - 1, height() - 1);
    p.drawRect(bounds);
    p.fillRect(bounds, Qt::white);

    for (int i = 0; i < m_worldSize; i++) {
        double columnX = (i * width()) / m_worldSize;
        QLineF columnLine(columnX, 0, columnX, height());
        p.drawLine(columnLine);

        double rowY = (i * height()) / m_worldSize;
        QLineF rowLine(0, rowY, width(), rowY);
        p.drawLine(rowLine);
    }
    // Paint cells
    double cWidth = (double) width() / m_worldSize;
    double cHeight = (double) height() / m_worldSize;
    for (int x = 0; x < m_worldSize; x++) {
        for (int y = 0; y < m_worldSize; y++) {
            if (m_cells.find(Cell(getOriginX() + x, getOriginY() + y)) != m_cells.end()) {
                QRectF cell(cWidth * x, cHeight * y, cWidth, cHeight);
                p.fillRect(cell, Qt::blue);
            }
        }
    }
}
