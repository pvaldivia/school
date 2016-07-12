#ifndef CIRCLE_H_
#define CIRCLE_H_

#include<iostream>
#include"shape.h"

using namespace std;

class Circle : public Shape
{
    public:
        Circle(int,int);
        void draw(Grid &);
        
};

#endif
