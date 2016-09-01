#include"doublylinkedlist.h"

DoublyLinkedList::DoublyLinkedList()
{
    m_head = NULL;
    m_tail = m_head;
    m_current = m_head;
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *ptr = m_head;
    while (ptr != NULL)
    {
        Node *temp;
  	temp = ptr;
	ptr = ptr->m_next;
	delete temp->m_data;
        delete temp;
    }
}

bool DoublyLinkedList::empty()
{
    if (m_head == NULL)
    return true;

    return false;
}

void DoublyLinkedList::append(string &data)
{
    string *temp_string = new string(data);
    if (m_head == NULL)
    {
        m_head = new Node(temp_string,m_head,NULL);
        m_current = m_head;
        m_tail = m_head;
    }
    else
    { 
    	m_tail->m_next = new Node(temp_string,m_tail->m_next,m_tail);
    	m_tail = m_tail->m_next;
    	m_current = m_tail;
    }
}

void DoublyLinkedList::begin()
{
    if (m_head == NULL || m_head->m_next == NULL)
    return;

    m_current = m_head;
}

void DoublyLinkedList::end()
{
   if (m_head == NULL || m_head->m_next == NULL)
   return;

   m_current = m_tail;  
}

/*void DoublyLinkedList::begin(vector<string*> & data)
{
    if (m_head == NULL)
    return;

    while (m_current != NULL)
    {
        data.push_back(m_current->m_data);
        m_current = m_current->m_next;
    }
    m_current = m_tail;
}*/

/*void DoublyLinkedList::end(vector<string*> & data)
{
    if (m_head == NULL)
    return;

    while (m_current != NULL)
    {
	data.push_back(m_current->m_data);
	m_current = m_current->m_prev;
    }
    m_current = m_head;
}*/

void DoublyLinkedList::insertBefore(string &data)
{
    string *temp_string = new string(data);
    if (m_head == NULL)
    {
	m_head = new Node(temp_string,m_head,NULL);
	m_current = m_head;
	m_tail = m_head;
    }
    else if (m_current->m_prev == NULL)
    {
	m_head = new Node(temp_string,m_head,NULL);
	m_current->m_prev = m_head;
	m_current = m_current->m_prev;
    }
    else
    {
    	Node *ptr = m_current->m_prev;
    	ptr->m_next = new Node(temp_string,ptr->m_next,ptr);
    	m_current->m_prev = ptr->m_next;
    	m_current = ptr->m_next;
    }

}

void DoublyLinkedList::insertAfter(string &data)
{
    string *temp_string = new string(data);
    if (m_head == NULL)
    {
	m_head = new Node(temp_string,m_head,NULL);
	m_current = m_head;
	m_tail = m_head;
    }
    else if (m_current->m_next == NULL)
    {
	m_current->m_next = new Node(temp_string,m_current->m_next,m_current);
	m_current = m_current->m_next;
	m_tail = m_current;
    }
    else
    {
	m_current->m_next = new Node(temp_string,m_current->m_next,m_current);
	m_current = m_current->m_next;
    }
}

bool DoublyLinkedList::find(string &data)
{
    if (m_head == NULL)
    	return false;

    Node *ptr = m_head;

    while (ptr != NULL && *(ptr->m_data) != data)
    	ptr = ptr->m_next;

    if (ptr == NULL)
	return false;
    m_current = ptr;
    return true;
}

void DoublyLinkedList::remove(string &data)
{
    if (m_head == NULL)
    return;

    if (find(data))
    {
	if (m_current->m_prev == NULL && m_current->m_next == NULL)
	{
	    m_head = m_head->m_next;
	    delete m_current->m_data;
	    delete m_current;
	    m_current = m_head;
	    m_tail = m_head;
	}
	else if (m_current->m_prev == NULL)
	{
	    m_head = m_head->m_next;
	    m_head->m_prev = NULL;
	    delete m_current->m_data;
	    delete m_current;
	    m_current = m_head;
	}
	else if (m_current->m_next == NULL)
	{
	    Node *temp = m_current->m_prev;
	    temp->m_next = m_current->m_next;
 	    delete m_current->m_data;
            delete m_current;
            m_current = temp;
            m_tail = temp;
	}
	else
	{	
	    Node *temp_before = m_current->m_prev;
            Node *temp_after = m_current->m_next;
	    temp_before->m_next = m_current->m_next;
	    temp_after->m_prev = m_current->m_prev;
	    delete m_current->m_data;
	    delete m_current;
	    m_current = temp_after;
	}
    }
}

bool DoublyLinkedList::next()
{
    if (m_head == NULL || m_head->m_next == NULL || m_current == m_tail)
    return false;

    m_current = m_current->m_next;
    return true;
}

bool DoublyLinkedList::prev()
{
    if (m_head == NULL || m_head->m_next == NULL || m_current->m_prev == NULL)
    return false;

    m_current = m_current->m_prev;
    return true;
}

string DoublyLinkedList::getData()
{
    string data;
    data = *(m_current->m_data);
    return data;
}
