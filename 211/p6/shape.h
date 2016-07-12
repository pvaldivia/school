#ifndef SHAPE_H_
#define SHAPE_H_

#include<iostream>
#include"grid.h"

using namespace std;

class Shape
{
    public: 
        Shape(int,int);
        virtual void draw(Grid &);
    protected:
        int m_x;
        int m_y;
};

#endif
