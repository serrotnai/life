#ifndef GAMECANVAS_H
#define GAMECANVAS_H

#include <QWidget>
#include <QTimer>
#include "cell.h"
#include <unordered_set>

// Class: GameCanvas
// The canvas that displays the current state of the game world.

class GameCanvas : public QWidget
{
    Q_OBJECT
public:
    GameCanvas(QWidget *parent = 0);

    // Loads a properly formatted text file containing a set of coordinates
    // into the game canvas. A properly formatted file consists of pairs of
    // integers separated by a single space, each on a separate line.
    void loadFile(QString filename);

    // Sets the origin of the game canvas to a given coordinate.
    // The origin is the top-leftmost point on the game canvas.
    void setOrigin(long long x, long long y);

    long long getOriginX(); // Returns the x-coordinate of the origin
    long long getOriginY(); // Returns the y-coordinate of the origi.

public slots:
    void tick(); // Steps the game canvas forward one generation.
    void animate(); // Animates the game canvas until the user presses the pause button
    void pause(); // Pauses the game canvas if it is currently being animated
    void setSize(int size); // Sets size of the game canvas
    void setSpeed(int speed); // Sets speed (in milliseconds between ticks)

private:
    void addCell(long long x, long long y); // Adds a cell with the given coordinates.
    void paintEvent(QPaintEvent *e); // Draws the grid and all live cells.

    std::unordered_set<Cell> m_cells; // Set of live cells in the current generation
    long long m_originX; // x-coordinate of origin
    long long m_originY; // y-coordinate of origin
    long long m_worldSize; // Size of the game world
    int m_animSpeed; // Constant for controlling animation speed
    QTimer m_timer; // Timer for controlling animation of canvas
};

#endif // GAMECANVAS_H
