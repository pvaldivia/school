#ifndef LIST_H_
#define LIST_H_

#include<iostream>


using namespace std;

class List
{
    public:
    List();
    ~List();
    void print();
    void insert (int value);
    //FUNCTIONS i WRITE TO TEST
    bool smallest_largest(int &smallest, int &largest);
    bool delete_value(int target);
    bool contains_sequence(int sequence[], int size);

    private:
        class Node
        {
            public:
                Node (int value, Node *next) {m_value = value; m_next = next;}
                int m_value;
                Node *m_next;
        };
        Node *m_head;
};

#endif
