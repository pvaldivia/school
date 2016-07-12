#include"smile.h"

Smile::Smile(int x, int y) : Shape(x,y)
{}

void Smile::draw(Grid &grid)
{
    for (int i = 1; i < 5; i++)
    {
        grid.set(m_x + i,m_y, '*');
        grid.set(m_x,m_y + i, '*');
        grid.set(m_x + i,m_y + 5, '*');
        grid.set(m_x + 5,m_y + i, '*');
        grid.set(m_x + i,m_y + 4,'-');
    }

    grid.set(m_x + 1,m_y + 2,'<');
    grid.set(m_x + 4,m_y + 2,'>');
    grid.set(m_x + 2,m_y + 2,'>');
    grid.set(m_x + 3,m_y + 2,'<');
    grid.set(m_x + 3,m_y + 3,'>');
    grid.set(m_x + 1,m_y + 1,'_');
    grid.set(m_x + 4,m_y + 1,'_');
}
