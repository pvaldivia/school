#ifndef GRID_H_
#define GRID_H_

#include<iostream>
#include<vector>


using namespace std;

typedef vector < vector <char> > Matrix;

class Grid
{
    public:
        Grid();
        void set(int,int,char);
        void print();
    private:
        Matrix grid;
};

#endif
