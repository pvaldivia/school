bool List::smallest_largest(int &smallest, int &largest)
{
    Node *ptr = m_head;
    if (ptr == NULL)
    {
        return false;
    }

    smallest = ptr->m_value;
    largest = ptr->m_value;
    while (ptr != NULL)
    {
        if (ptr->m_value < smallest)
        {
            smallest = ptr->m_value;
        }
        if (ptr->m_value > largest)
        {
            largest = ptr->m_value;
        }
        ptr = ptr->m_next;
    }
    return true;
}
