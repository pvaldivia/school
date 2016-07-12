#include"square.h"

Square::Square(int x, int y, int length) : Shape(x,y)
{
    m_length = length;
}

void Square::draw(Grid &grid)
{
    for(int i = 0; i < m_length; i++)
    {
        grid.set(m_x + i, m_y, '*');
        grid.set(m_x, m_y + i, '*');
    }

    for (int i = 0; i < m_length; i++)
    {
        grid.set(m_x + i, m_y + (m_length - 1), '*');
        grid.set(m_x + (m_length - 1), m_y + i, '*');
    }
}
