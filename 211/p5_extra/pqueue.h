//pqueue.h
//Valdivia, Pedro
//pvaldivai1

#ifndef PQUEUE_H_
#define PQUEUE_H_

#include<iostream>
#include"cust.h"

using namespace std;

class Pqueue
{
    public:
        Pqueue();
        ~Pqueue();
        bool dequeue(int &);
        Cust *dequeue();
        void enqueue(Cust *, int);
        bool empty();
        void print();
        int first_priority();
        int length();
    private:
        class Node
        {
            public:
                Node(Cust *cust,Node *next,int priority)
                {pqueue_cust = cust; pqueue_next = next; pqueue_priority = priority;}
                Cust *pqueue_cust;
                Node *pqueue_next;
                int pqueue_priority;
        };
        Node *pqueue_head = NULL;
};

#endif
