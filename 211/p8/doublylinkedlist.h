#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include<iostream>
#include<string>
#include<vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class DoublyLinkedList
{
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool empty();
    void append(string&);
    void insertBefore(string&);
    void insertAfter(string&);
    void remove(string&);
    void begin();
    void end();
    bool next();
    bool prev();
    bool find(string&);
    string getData();

    private:
        class Node 
        {
            public:
            Node (string* data, Node *next, Node *prev)
            {m_data = data; m_next = next; m_prev = prev;}
            string *m_data;
            Node *m_next;
            Node *m_prev;
        };
        Node *m_head;
        Node *m_tail;
        Node *m_current;

};

#endif

