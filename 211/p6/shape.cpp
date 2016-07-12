#include"shape.h"

Shape::Shape(int x, int y)
{
    m_x = x;
    m_y = y;
}

void Shape::draw(Grid &grid)
{
    cout << "Shape draw was called" << endl;    
}
