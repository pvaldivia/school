#ifndef POINT_H_
#define POINT_H_

#include<iostream>
#include"shape.h"
#include"grid.h"

using namespace std;

class Point : public Shape
{
    public:
        Point(int,int,char);
        void draw(Grid &);
   private:
        char m_character;
};

#endif
