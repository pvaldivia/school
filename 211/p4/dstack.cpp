//dstack.cpp
//Valdivia, Pedro
//pvaldivia1

#include"dstack.h"

Dstack::Dstack()
{
    dstack_head = NULL;
}

Dstack::~Dstack()
{
    Node *ptr = dstack_head;
    while(ptr != NULL)
    {
        Node *temp;
        temp = ptr;
        ptr = ptr->dstack_next;
        delete temp;
    }
}

void Dstack::print()
{
    Node *ptr = dstack_head;
    while (ptr != NULL)
    {
        cout << ptr->dstack_value << endl;
        ptr = ptr->dstack_next;
    }
}

void Dstack::push(double value)
{
        dstack_head = new Node(value,dstack_head);
}

bool Dstack::pop(double &value)
{
    if (dstack_head == NULL)
    {
        return false;
    }

    if (dstack_head->dstack_next == NULL)
    {
        
        Node *temp = dstack_head;
        value = temp->dstack_value;
        dstack_head = temp->dstack_next;
        delete temp;
        return true;
    }

    Node *temp = dstack_head;
    value = temp->dstack_value;
    dstack_head = temp->dstack_next;
    delete temp;
    return true;
}

int Dstack::size()
{
    int length = 0;
    if (dstack_head == NULL)
    {
        return length;
    }

    Node *ptr = dstack_head;
    while (ptr != NULL)
    {
        ptr = ptr->dstack_next;
        length++;
    }
    return length;
}

bool Dstack::empty()
{
    if (dstack_head == NULL)
    {
        return true;
    }
    return false;
}

