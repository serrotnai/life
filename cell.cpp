#include "cell.h"

Cell::Cell(long long x, long long y)
{
    m_x = x;
    m_y = y;
    m_count = 0;
}

long long Cell::getX() const
{
    return m_x;
}

long long Cell::getY() const
{
    return m_y;
}

bool operator==(const Cell& c1, const Cell& c2)
{
    return c1.getX() == c2.getX() && c1.getY() == c2.getY();
}
