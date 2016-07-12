//dstack.h
//Valdivia, Pedro
//pvaldivia1
#ifndef DSTACK_H
#define DSTACK_H
#include<iostream>

using namespace std;

class Dstack
{
    public:
        Dstack();
        ~Dstack();
        void push(double value);
        bool pop(double &value);
        int size();
        bool empty();
        void print();
    private:
        class Node
        {
            public:
                Node(double value,Node *next)
                {dstack_value = value; dstack_next = next;}
                double dstack_value;
                Node *dstack_next;
        };
        Node *dstack_head;
};

#endif
