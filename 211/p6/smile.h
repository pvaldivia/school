#ifndef SMILE_H_
#define SMILE_H_

#include"shape.h"

using namespace std;

class Smile : public Shape
{
    public:
        Smile(int,int);
        void draw(Grid &);
};

#endif
