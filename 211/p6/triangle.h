#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include<iostream>
#include"shape.h"

using namespace std;

class Triangle : public Shape
{
    public: 
        Triangle(int,int);
        void draw(Grid &);
};

#endif
