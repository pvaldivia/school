bool List::delete_value(int target)
{
    if (m_head == NULL)
    {
        return false;
    }

    if (m_head->m_value == target)
    {
        Node *ptr temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        return true;
    }

    Node *ptr = m_head;
    while (ptr->m_next != NULL && target != ptr->m_next->m_value)
    {
        ptr = ptr->m_next;        
    }

    if (ptr->m_next == NULL)
    {
        return false;
    }
    
    Node *temp = ptr->m_next;
    ptr->m_next = temp->m_next;
    delete temp;
    return true;
    
}
