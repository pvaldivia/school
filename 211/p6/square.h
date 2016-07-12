#ifndef SQUARE_H_
#define SQUARE_H_

#include<iostream>
#include"shape.h"

using namespace std;

class Square : public Shape
{
    public:
        Square(int,int,int);
        void draw(Grid &);
    private:
        int m_length;
};

#endif
