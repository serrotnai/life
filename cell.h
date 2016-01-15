#ifndef CELL_H
#define CELL_H

#include <cstddef>
#include <functional>

class Cell
{
public:
    Cell(long long x, long long y);
    long long getX() const; // Returns x-coordinate of cell
    long long getY() const; // Returns y-coordinate of cell

    mutable int m_count; // Number of live neighbors when calculating next generation

private:
    long long m_x; // x-coordinate of cell
    long long m_y; // y-coordinate of cell
};

/* Returns true if two cells have the same x and y coordinates */
bool operator==(const Cell& c1, const Cell& c2);


/* Custom hash function for Cell class to be used by unordered_set. */
namespace std
{
    template <>
    struct hash<Cell>
    {
        size_t operator()(const Cell& c) const
        {
            size_t result = 17;
            result = result * 37 + hash<long long>()(c.getX());
            return result * 37 + hash<long long>()(c.getY());
        }
    };
}

#endif // CELL_H
