// Fill in the functions at the bottom of this file
// 
#include <iostream>
using namespace std;
#include "list.h"

// on some machines member variables are not automatically initialized to 0
List::List()
{
    m_head = NULL;
}

// delete all Nodes in the list
// since they are dynamically allocated using new, they won't go away
// automatically when the list is deleted
// Rule of thumb: destructor deletes all memory created by member functions
List::~List()
{
    while (m_head)
    {
        Node *tmp = m_head;
        m_head = m_head->m_next;
        delete tmp;
    }
}

// always insert at the front of the list
// Note: this works even in the SPECIAL CASE that the list is empty
void List::insert(int value)
{
    if (m_head == NULL)
    {
        m_head = new Node(value, m_head);
    }
    else
    {
        Node *ptr = m_head;
        while (ptr->m_next != NULL)
        {
            ptr = ptr->m_next;
        }
        ptr->m_next = new Node (value,NULL);
    }
}

// iterate through all the Nodes in the list and print each Node
void List::print()
{
    for (Node *ptr = m_head; ptr; ptr = ptr->m_next)
    {
        cout << ptr->m_value << endl; 
    }
}


bool List::contains_sequence(int sequence[], int size)
{
    if (m_head == NULL)
    {
        return false;
    }

    Node *ptr = m_head;
    Node *temp = m_head;
    int index;
    while (ptr != NULL)
    {
        index = 0;
        temp = ptr;
        while (temp != NULL && temp->m_value == sequence[index])
        {
            index++;
            temp = temp->m_next;
            if (index == size)
            {
                return true;
            }
        }
        ptr = ptr->m_next;
    }
    return false;
}
